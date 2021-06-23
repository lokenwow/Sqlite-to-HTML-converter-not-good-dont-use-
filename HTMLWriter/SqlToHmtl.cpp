#include "SqlToHmtl.hpp"
#include <iostream>
using namespace std;


/**
*sets the variables values for path_ and sqlFile_ and creates a new conmsolehelper and dbhelper. 
*in the future this will be fleshed out to provide CMD launch options.
*/
SqlToHtml::SqlToHtml(string path, string sqlFile)
    : path_ {path}
    , sqlFile_ {sqlFile}
{
	consoleHelper = new ConsoleHelper();
    dbHelper = new DbHelper("TODO filename");

}

/**
*calls the MainMenu function
*/
void SqlToHtml::run()
{
    MainMenu(); 
}

/**
* Declares inputoption and inputid
* while input is 6 quit program
* while anything but 6:
* 
* call PrintMainMenu from consolehelper object
* give inputOption a value equal to the return of GetMenuInput with 1 and 6 sent as params.
* 
* open switch statement with InputOption
* 
* case option 1: 
* Calls saveAlltoHtml function then breaks.
* 
* case option 2:
* Calls displayIndexRaw function then breaks.
* 
* case option 3:
* Calls displayIndexHtml function 
* call getIndex and use the return value as a param for ElementMenuForIndex
* then break
* 
* case option 4:
* 
* call GetIdInput from consolehelper object
* save that result to inputId
* call displayDetailsRaw sending inputId as a param
* break
* 
* case option 5:
* 
* call GetIdInput from consolehelper object
* save that result to inputId
* call displayDetailsHtml sending inputId as a param
* call getDetails sening inputId as a param
* use result as a param with inputId to call ElementMenuForDetails
* break
* 
* case option 6:
* break
* ends program
*/
void SqlToHtml::MainMenu() {
    
    int inputOption;
    string inputId;

    do {
	    consoleHelper->PrintMainMenu();
	    inputOption = consoleHelper->GetMenuInput(1,6);

        switch (inputOption)
        {
        case 1:
            //cout << "saveAllToHtml";
            saveAllToHtml();
            break;
        case 2:
            //cout << "displayAllRaw";
            displayIndexRaw();
            break;
        case 3:
            //cout << "displayAllHtml";
            //Reading info from database twice in these two methods. thats naughty, be better!
            displayIndexHtml();
            ElementMenuForIndex(getIndex());
            break;
        case 4:
            inputId = consoleHelper->GetIdInput();
            displayDetailsRaw(inputId);
            break;
        case 5:
            inputId = consoleHelper->GetIdInput();
            displayDetailsHtml(inputId);
            ElementMenuForDetails(getDetails(inputId), inputId);

            //MENU
            break;
        case 6: 
            //cout << "Quit Sucessful";
            break;
        //default:
        //    std::cout << "ERROR! You have selected an invalid choice." << std::endl;
        //    break;
        }

        //All done

    } while (inputOption != 6);

    cout << endl << "All done, goodbye!" << endl;
}

/**
* elemenet Menu: 
* -save to file -> save -> into -> menu
* -add element  -> ask tag -> ask innerhtml -> fineMenu
* -cancel all and go to menu -> menu
* 
*/




/**
* recieves an IndexPage object
* declares int inputOption
* declare a vector of strings
* 
* while inputOption is <2:
* 
* Call PrintElementMenu from the consoleHelper object
* set value of InputOption to the return of GetMenuInput sending the params 1 and 3.
* 
* open switch statement with InputOption
* 
* case Option 1:
* Set value of data to the return of createElement
* calling constructor for HtmlElement sending it the index 0 and 1 as params
* if entry:
* call size on data, if equal to 3 enter if statement
*   if 3:
*       call AddAttribute passing string and index 2 of data on HtmlElement object 
*   exit if
* call addCustomElement passing HtmlElement object as a param on page
* break
* 
* case option 2:
* call saveIndexToFile sending param page
* break
* exit do while
* 
* case option 3:
* break
* exit do while
*/
void SqlToHtml::ElementMenuForIndex(IndexPage page) {
    
    int inputOption;
    //HtmlElement element();
    vector<string> data;

    do {       
	    consoleHelper->PrintElementMenu();
	    inputOption = consoleHelper->GetMenuInput(1,3);

        switch (inputOption)
        {
        case 1:
        {
            //Add element to page
            data = consoleHelper->createElement();
            HtmlElement element(data[0], data[1]);

            if (data.size() == 3) 
                element.AddAttribute("href", data[2]);
            
            page.addCustomElement(element);
            break;
        }
        case 2:
            //Save to disk
            saveIndexToFile(page);
            break;
        case 3:
            //Quit without save and back to Mmenu
            break;
        }
    } while (inputOption < 2);
}



/**
* Recieving details page and a string as inputs
* declare int inputOption - inputOption
* declare string Vector - data
* 
* while input option is less than 2 enter do while
* 
* do while:
* call PrintElementMenu from consoleHelper
* save return value of GetMenuInput with params 1 and 3 into variable inputOption
* 
* enter switch with inputOption value while <2
* 
* case option 1:
* call createElement from consoleHelper and save value to data
* creat HtmlElement object passing params index 0 and 1 of vector data
* 
* if entry:
* call size on data, if equal to 3 enter if statement
*   if 3:
*      call AddAttribute passing string and index 2 of data on HtmlElement object 
*   exit if
* call addCustomElement sending element as param on page
* break
* 
* case option 2:
* call saveDetailsToFile sending page and inputID as params
* break
* exit do while
* 
* case option 3:
* break
* exit do while
*/
void SqlToHtml::ElementMenuForDetails(DetailsPage page, string inputId) {
    int inputOption;
    vector<string> data;


    do {       
	    consoleHelper->PrintElementMenu();
	    inputOption = consoleHelper->GetMenuInput(1,3);

        switch (inputOption)
        {
        case 1:
        {
            //add element
            data = consoleHelper->createElement();
            HtmlElement element(data[0], data[1]);

            if (data.size() == 3)
                element.AddAttribute("href", data[2]);

            page.addCustomElement(element);
            break;
        }
        case 2:
            //save
            saveDetailsToFile(page, inputId);
            break;
        case 3:
            //quit without save and back to Menu
            break;
        }
    } while (inputOption < 2);
}



/**
* recieves param indexPage object
* calls writeToDisk from FileHelper sending string, string and return value of getCode on page.
*/
void SqlToHtml::saveIndexToFile(IndexPage page)
{
    FileHelper::writeToDisk(path_, "index.html", page.getCode());
}


/**
* recieves params object of detailsPage and string
* calls writeToDisk from FileHelper sending sting, inputID + string, return value of getCode on page.
*/
void SqlToHtml::saveDetailsToFile(DetailsPage page, string inputId) {  
    FileHelper::writeToDisk(path_, inputId + ".html", page.getCode());
}


/**
* declares a vector of DbEntrys names data
* set value of data to the return value of FetchAll on dbHelper
* create new IndexPage object called index
* 
* enter foreach loop:
* 
* for each entry in data:
*   call addEntry passing entry on index
*   create new detailsPage object called details passing id of current entry
*   call addEntry passing entry on details
*   call addBackBtn on details
*   call writeToDisk from FileHelper sending srting, the id of current entry + string, return value of getCode on details.
* Exit foreach loop
* 
* call writeToDisk from FileHelper passing sting, string, return value of getCode on index.
*/
void SqlToHtml::saveAllToHtml()
{
    vector<DbEntry> data;
    data = dbHelper->FetchAll();
    IndexPage index;

    for (DbEntry entry : data) {
        //index
        index.addEntry(entry);
        //details
        DetailsPage details(entry.id_);
        details.addEntry(entry);
        details.addBackBtn();
        FileHelper::writeToDisk(path_, entry.id_ + ".html", details.getCode());
    }
    FileHelper::writeToDisk(path_, "index.html", index.getCode());
}


/**
* declare a vector of DbEntrys named data
* set value of data to return value of FetchAll from dbHelper
* enter foreach loop:
*   foreach entry in data
*   call printOneRaw passing current entry from consoleHelper
* exit foreach loop
*/
void SqlToHtml::displayIndexRaw()
{
    vector<DbEntry> data;
    data = dbHelper->FetchAll();
    for(DbEntry entry : data)
    {
        consoleHelper->PrintOneRaw(entry);
    }
}


/**
* declaring vector of DbEntrys called data
* set value of data to return value of FetchAll from DbHelper
* create new IndexPage object called indexPage
* entry for each loop:
*   for each entry in data
*   call AddEntry passing current entry on indexPage object
* exit foreach loop
* 
* return indexPage object
*/
IndexPage SqlToHtml::getIndex() {
    vector<DbEntry> data;
    data = dbHelper->FetchAll();

    IndexPage indexPage;
    for (DbEntry entry : data) 
    {
        indexPage.addEntry(entry);
    }

    return indexPage;
}


/**
* call PrintHtmlCode from consoleHelper passing the param the return value of getCode on getIndex
* 
*/
void SqlToHtml::displayIndexHtml()
{
    consoleHelper->PrintHtmlCode(getIndex().getCode());
}


/**
* Recieves a string - id
* creates a new DbEntry object called data and sets the value as the return value of FetchOne from DbHelper sending the param string id
* enter if else:
*   if variable id_ of data is equal to -1
*       call InvalidId from consoleHelper
*   else
*       call PrintOneRaw from consoleHelper passing data
* exit if else
*/
void SqlToHtml::displayDetailsRaw(string id) {
    DbEntry data = dbHelper->FetchOne(id);
    if(data.id_ == "-1")
        consoleHelper->InvalidId();
    else
        consoleHelper->PrintOneRaw(data);    
}


/**
* Recieves string - id
* creates new object of DbEntry - data and sets value as return value of FetchOne from DbHelper sending param id
* creates new object of DetailsPage - detailsPage passing param of string + id
* entry if else:
*   if value of id in data is equal to -1
*       call InvalidID from consoleHelper
*   else
*       call addEntry on detailsPage passing param data
*       call addBackBtn on detailsPage
* exit if else
* 
* return object detailsPage
*/
DetailsPage SqlToHtml::getDetails(string id)
{
    DbEntry data = dbHelper->FetchOne(id);
    DetailsPage detailsPage("Details for contact ID: " + id);

    if (data.id_ == "-1") 
        consoleHelper->InvalidId();   
    else {
        detailsPage.addEntry(data);
        detailsPage.addBackBtn();        
             
    }

    return detailsPage;
}


/**
* recieves string - id
* 
* creates an object Detailspage - detailsPage and sets value as return value of getDetails passing id as param
* enter if:
*   if return of getCounter on detailsPage is greater than 0
*       call PringHtmlCode from consoleHelper passing return value of getcode on detailsPage as param
* exit if
*/
void SqlToHtml::displayDetailsHtml(string id) {
    
    DetailsPage detailsPage = getDetails(id);

    if (detailsPage.getCounter() > 0) {
        consoleHelper->PrintHtmlCode(detailsPage.getCode());
    }
}