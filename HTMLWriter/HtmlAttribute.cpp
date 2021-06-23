#include "HtmlAttribute.hpp"

/**
* overloaded Constructor
*/
HtmlAttribute::HtmlAttribute(std::string name, std::string value)

	: name{ name }
	, value { value }
{
#ifdef _DEBUG
	//std::cout << "greetings from the constructor\n";
#endif
}
