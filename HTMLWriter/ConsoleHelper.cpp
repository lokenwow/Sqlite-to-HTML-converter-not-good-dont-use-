#include "ConsoleHelper.hpp"


/**
* Prints main menu to console
*/
void ConsoleHelper::PrintMainMenu()
{
    std::cout << "********** Main Menu **********" << std::endl;
    std::cout << "(1): Save all to HTML" << std::endl;
    std::cout << "(2): Display index Raw" << std::endl;
    std::cout << "(3): Display Index HTML" << std::endl;
    std::cout << "(4): Display one Raw" << std::endl;
    std::cout << "(5): Display one HTML" << std::endl;
    std::cout << "(6): Quit Program" << std::endl;
}

/**
* prints element menu to console
*/
void ConsoleHelper::PrintElementMenu()
{
    std::cout << std::endl;
    std::cout << "********** Element Menu **********" << std::endl;
    std::cout << "(1): Add element " << std::endl;
    std::cout << "(2): Save to file" << std::endl;
    std::cout << "(3): Main Menu" << std::endl;
}

/**
* recieves 2 ints
* 
* takes useer input, validates input between lower and higher bounds
* returns an input
* 
* if you are a failure:
* return 0
*/
int ConsoleHelper::GetMenuInput(int lb, int hb)
{
    //may have had some issues with infinite loops so....
    //idiot proofing (not that i need it)
    //if (lb >= hb) 
        //return false;

    int i = 0;

    while (true) {
        int input;

        cout << "Please enter a number: ";

        cin >> input;

        if (cin.fail()) {
            cout << "Input incorrect, try again ";
        }

        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if (input >= lb && input <= hb)
            return input;


        if (i >= 10) // if you fail 10 times it just stops to save sanity 
            return 0;

        i++;
    }
}


/**
* promts for input and takes user input
* returns the input
*/
string ConsoleHelper::GetIdInput()
{
    string input;
    cout << "Enter ID: ";
    cin >> input;
    //Do some checks on input in next version. 
    return input;
}


/**
* Takes in a DbEntry
* prints contents of DbEntry to console
*/
void ConsoleHelper::PrintOneRaw(DbEntry e)
{
    //cout << "ID: " << e.id_ << "\n" << "First name: " << e.firstName_ << "\n" << "Last Name: "<< e.lastName_ << "\n" << "Email: " << e.email_ << "\n" << "Coutnry code: " << e.countrycode_ << "\n" << "Flag: " << e.filename_ << "\n" << "Catagory: " << e.catagory_ << "\n";
    cout << "ID: " << e.id_ << "\n"; 
    cout << "First name: " << e.firstName_ << "\n";
    cout << "Last Name: " << e.lastName_ << "\n";
    cout << "Email: " << e.email_ << "\n";
    cout << "Country code: " << e.countrycode_ << "\n";
    cout << "Flag file: " << e.filename_ << "\n";
    cout << "Catagory: " << e.catagory_ << "\n";
}

/**
* recieves a string
* 
* prints "html" to console
*/
void ConsoleHelper::PrintHtmlCode(string html)
{
    cout << html;
}

/**
* prints error to comsole
*/
void ConsoleHelper::InvalidId()
{
    cout << "You failed to enter a valid ID!" << "\n";
}

/**
* prints create element menu to console
* promts and takes in user input for int i
* promts and takes in user input for string innerHtml
* 
* if else:
*   if p then push into data
* 
*   else prompt for link
*   push all 3 into data
* 
* return vector of strings data
* 
*/
vector<string> ConsoleHelper::createElement()
{

    vector<string> data;
    

    cout << "Select Element to add: "<< std::endl;
    cout << "(1) p"<< std::endl;
    cout << "(2) a"<< std::endl;

    cout << "Enter: ";
    int i;
    cin >> i;

    //get input for inner Html either way
    cout << std::endl << "Enter innerHtml: ";
    string innerHtml;
    getline(cin >> ws, innerHtml);
    

    if (i == 1) {
        //p
        data.push_back("p");
        data.push_back(innerHtml);
    }
    else {
        //a
        cout << std::endl << "Enter link: ";
        string link;
        getline(cin >> ws, link);

        data.push_back("a");
        data.push_back(innerHtml);
        data.push_back(link);
    }
    return data;

}



