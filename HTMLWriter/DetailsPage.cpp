#include "DetailsPage.hpp"

/**
* recieves a string
* sets title of variable title in base class (pure magic)
* sets entryCounter to 0
*/
DetailsPage::DetailsPage(string title2)
{
	//this is wizardry dont ask how long this took.
	base:title = title2;
	entryCounter = 0;
}

/**
* recieves object DbEntry
* 
* pushes an HtmlElement into htmlVE passing params from dbEntry into the constructor
* incriment entryCounter
*/
void DetailsPage::addEntry(DbEntry dbEntry)
{
	htmlVE.push_back(HtmlElement("h1", dbEntry.id_));
	htmlVE.push_back(HtmlElement("p", dbEntry.firstName_));
	htmlVE.push_back(HtmlElement("p", dbEntry.lastName_));
	htmlVE.push_back(HtmlElement("p", dbEntry.email_));
	htmlVE.push_back(HtmlElement("p", dbEntry.countrycode_));
	htmlVE.push_back(HtmlElement("p", dbEntry.catagory_));
	htmlVE.push_back(HtmlElement("p", dbEntry.flag_png_));
	htmlVE.push_back(HtmlElement("p", dbEntry.name_));

	entryCounter++;
}

//<a href="index.html"><p>Go back to index</p></a>

/**
* creates a link element and adds it the htmlVE via pushback
*/
void DetailsPage::addBackBtn() {
	HtmlElement* link = new HtmlElement("a");
	link->AddAttribute("href", "index.html");

	HtmlElement* para = new HtmlElement("p", "Go back to index");

	link->AddChild(*para);
	htmlVE.push_back(*link);
}
