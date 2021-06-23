#pragma once
#include <string>
#include <vector>
#include "HtmlAttribute.hpp"
using namespace std;

class HtmlElement
{
public:

	HtmlElement(std::string tagName);
	HtmlElement(std::string tagName, std::string innerHtml);
	~HtmlElement();

	void AddChild(HtmlElement htmlElement);
	void AddAttribute(std::string name, std::string value);
	bool HasAttribute();
	bool HasChild();
	vector <HtmlAttribute> GetAttributes();
	vector <HtmlElement> GetChildren();
	string GetStartTag(bool endBracket);
	string GetEndTag();
	string GetInnerHtml();

private:
	string tagName;
	string innerHtml;
	vector <HtmlAttribute> attribute;
	vector <HtmlElement> children;

};

