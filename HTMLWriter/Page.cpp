#include "Page.hpp"



/**
* getter for header or a header getter if you will.
* throws strings and title into header and returns header
*/
string Page::getHeader()//TODO: use string builder
{
    
    string header = "<!DOCTYPE html><html lang = \"en\"> <head> <meta charset = \"UTF-8\">"; 
    header += "<title> " + title + " </title>"; 
    header += "<meta name = \"viewport\"content =\"width=device-width,initial-scale=1\"> ";
    header += "<style> table, th, td {border: 1px solid black;} table {width: 80%; margin: auto;}</style>";
    header += "</head><body> <table>";

    return header;
}

/**
* Getter for footer (end tags).
*/
string Page::getFooter()
{
    return "</table> </body> </HTML>";
}

/**
* creates a new page
* adds a header
* steps through foreach adding HtmlElements to page
* adds footer
* retuns page
*/
string Page::getCode()
{
    string page;
        
    page += getHeader();
    for (HtmlElement e : htmlVE) {
        page += decodeElement(e);
    }

    page += getFooter();

    return page;
}

/**
* Recieves object of HtmlElement
* if the htmlElement has no attribute then send a closed start tag
* else send an open start tag
*   for each attribute
*       add atrtributes to end of open start tag
*   end for each
* close start tag
* 
* if htmlElement has child
*   for each child 
*       add code to "code" from each child
*   end for each
* else
*   add innerHtml to code object
* 
* add end tag
* 
* return code
*/
string Page::decodeElement(HtmlElement htmlElement)// this is a horrible mess. refactor at some point!
{
    string code;

    if (htmlElement.HasAttribute() != true) {
        code += htmlElement.GetStartTag(true); // <tag>
    }
    else {
        code += htmlElement.GetStartTag(false); // <tag
        for (HtmlAttribute a : htmlElement.GetAttributes()) {
            code += " " + a.name + "=\"" + a.value + "\""; //<tag style="blue" style="blue"
        }
        code += ">"; //<tag style="blue" style="blue">
    }

    if (htmlElement.HasChild()) {
        for (HtmlElement child : htmlElement.GetChildren()) {
            code += decodeElement(child);
        }
    }
    else {
        code += htmlElement.GetInnerHtml(); //<tag style="blue" style="blue">innercrap
    }


    code += htmlElement.GetEndTag(); //<tag style="blue" style="blue">innercrap</tag> (without Child) //
    return code;
}

/**
* recieves HtmlElement
* pushes element into htmlVE
*/
void Page::addCustomElement(HtmlElement htmlElement)
{
    htmlVE.push_back(htmlElement);
}

/**
* Getter for entryCounter
*/
int Page::getCounter()
{
    return entryCounter;
}

/**
* recieves a string and 2 ints
* creates HtmlElement object passing string
* sets width amd height
* creates HtmlElement object passing string and bmpData
* 
* add data as child of img
* return img (pointer)
*/
HtmlElement Page::createImageFromString(string bmpData, int width, int height)
{	
    HtmlElement* img = new HtmlElement("img");
	img->AddAttribute("width", to_string(width));
	img->AddAttribute("height", to_string(height));

	HtmlElement* data = new HtmlElement("data", bmpData);

	img->AddChild(*data);

	return *img;
}

//tagName, InnerHTML, vector<HtmlElements>, vector<HtmlAttributes>

