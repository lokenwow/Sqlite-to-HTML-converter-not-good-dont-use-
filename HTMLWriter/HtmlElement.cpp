#include "HtmlElement.hpp"



/**
* Overloaded CSTR: takes in a tagname creates an element with that tag
*/
HtmlElement::HtmlElement(std::string tagName)
	:tagName { tagName}
{
	
}


/**
* Overloaded CSTR: takes in a tag name and inner content and dreates an Element with that tage and content.
*/
HtmlElement::HtmlElement(std::string tagName, std::string innerHtml)
	:tagName	{ tagName }
	,innerHtml	{ innerHtml }
{

}

/**
* deconstructor
*/
HtmlElement::~HtmlElement()
{
#ifdef _DEBUG
	//std::cout << "greetings from the destructor\n";
#endif
}

/**
* recieves an HtmlElement
* adds it as a child of HtmlElement
*/
void HtmlElement::AddChild(HtmlElement htmlElement)
{
	children.push_back(htmlElement);
}


/**
* recieves 2 strings
* 
* creates object of htmlAttribute using passed params
* 
* pushes new htmlAttribute into attribute.
*/
void HtmlElement::AddAttribute(std::string name, std::string value)
{
	HtmlAttribute* htmlAttribute = new HtmlAttribute(name, value);

	attribute.push_back(*htmlAttribute);
}


/**
* performs check to see if attribute is empty.
*/
bool HtmlElement::HasAttribute()
{
	return !attribute.empty();
}


/**
* performs check to see if Element is pregnant. (has a child)
*/
bool HtmlElement::HasChild()
{
	return !children.empty();
}


/**
* simple getter for attribute
*/
std::vector <HtmlAttribute> HtmlElement::GetAttributes()
{
	return attribute;
}


/**
* Getter for the Start Tag, takes in a bool so it knows if it shoudl add a closing brace. (<p> or <a for example)
*/
std::string HtmlElement::GetStartTag(bool endBracket)
{
	string startTag = "<" + tagName;

	startTag += endBracket ? ">" : " ";
	
	return startTag;
}


/**
* getter for end tag
*/
std::string HtmlElement::GetEndTag()
{
	return "</" + tagName + ">";
}


/**
* Getter for InnerHtml
*/
std::string HtmlElement::GetInnerHtml()
{
	return innerHtml;
}

/**
* Getter for any Children
*/
vector <HtmlElement> HtmlElement::GetChildren()
{
	return children;
}
