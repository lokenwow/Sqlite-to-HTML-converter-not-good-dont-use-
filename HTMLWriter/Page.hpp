   #pragma once
#include <string>
#include <vector>
#include "HtmlElement.hpp"
using namespace std;

class Page
{
public:
	string getHeader();
	string getFooter();
	string getCode();
	string decodeElement(HtmlElement htmlElement);
	void addCustomElement(HtmlElement htmlElement);
	int getCounter();

private:

protected:
	int entryCounter;
	string title;
	vector<HtmlElement> htmlVE;
	HtmlElement createImageFromString(string bmpData, int width, int height);
};

