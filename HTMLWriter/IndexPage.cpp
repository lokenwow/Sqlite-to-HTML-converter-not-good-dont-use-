#include "IndexPage.hpp"


/**
* sets title to index
* sets entryCounter to 0
*/
IndexPage::IndexPage()
{
	title = "index";
	entryCounter = 0;
}

//<tr><td></td><td>name</td></tr>
//<a href='#'>id</a> - HtmlElement* link = new HtmlElement("a");

/**
* This puts a single entry into the index page
* 
* Recieves DbEntry
* creates a link element for with the id of the entry
* 
* creates an element for a bunch of data in the entry
* adds children where apprortiate to finish tags.
* pushes everything into htmlVE
* 
* increments entryCounter
* 
*/
void IndexPage::addEntry(DbEntry dbEntry)
{
	HtmlElement* link = new HtmlElement("a", dbEntry.id_);
	link->AddAttribute("href", dbEntry.id_ + ".html");

	HtmlElement* tr = new HtmlElement("tr"); 

	HtmlElement* td1 = new HtmlElement("td");
	HtmlElement* td2 = new HtmlElement("td", dbEntry.firstName_);
	HtmlElement* td3 = new HtmlElement("td", dbEntry.lastName_);
	HtmlElement* td4 = new HtmlElement("td", dbEntry.email_);
	HtmlElement* td5 = new HtmlElement("td", dbEntry.countrycode_);
	HtmlElement* td6 = new HtmlElement("td", dbEntry.catagory_);
	HtmlElement* td7 = new HtmlElement("td", dbEntry.filename_);
	HtmlElement* td8 = new HtmlElement("td");
	HtmlElement* td9 = new HtmlElement("td", dbEntry.name_);


	//HtmlElement* img = &createImageFromString(dbEntry.flag_png_, 100, 100);

	td8->AddChild(createImageFromString(dbEntry.flag_png_, 100, 100));
	td1->AddChild(*link);
	tr->AddChild(*td1);
	tr->AddChild(*td2);
	tr->AddChild(*td3);
	tr->AddChild(*td4);
	tr->AddChild(*td5);
	tr->AddChild(*td6);
	tr->AddChild(*td7);
	tr->AddChild(*td8);
	tr->AddChild(*td9);

	htmlVE.push_back(*tr);

	entryCounter++;
}
