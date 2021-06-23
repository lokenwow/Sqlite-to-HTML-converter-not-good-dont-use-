#include "pch.h"
#include "CppUnitTest.h"
#include "../HTMLWriter/ConsoleHelper.cpp"
//#include "../HTMLWriter/DbEntry.hpp"
#include "../HTMLWriter/HtmlElement.cpp"
#include "../HTMLWriter/Page.hpp"
#include "../HTMLWriter/HtmlAttribute.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HTMLWriterUT
{
	TEST_CLASS(HTMLWriterUT)
	{
	public:

		TEST_METHOD(InvalidId_Test_Pass)
		{
			//making the string thats expected
			std::string expected = "You failed to enter a valid ID!\n";

			//This does some magic storing the output to the console
			std::stringstream buffer;
			std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

			// BEGIN: Code being tested
			ConsoleHelper ch;
			ch.InvalidId(); 
			// END:   Code being tested

			//to_string for the output of the console
			std::string text = buffer.str();

			//Comparing outputs
			Assert::AreEqual(expected, text);
		}

		TEST_METHOD(GetStartTagTest_Test_pass)
		{
			//making the string thats expected
			std::string ExpectedTag = "<p>";
			
			// BEGIN: Code being tested
			HtmlElement he("p");
			// END:   Code being tested

			//Comparing outputs
			Assert::AreEqual(ExpectedTag, he.GetStartTag(true));
		}

	};
}
