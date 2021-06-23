#pragma once
#include "ConsoleHelper.hpp"
#include "DbHelper.hpp"
#include "IndexPage.hpp"
#include "DetailsPage.hpp"
#include "FileHelper.hpp"

class SqlToHtml
{

public:
	SqlToHtml(string path, string sqlFile);
	void run();
	void MainMenu();
	void ElementMenuForIndex(IndexPage page);
    void ElementMenuForDetails(DetailsPage page, string inputId);
	void saveIndexToFile(IndexPage page);
	void saveDetailsToFile(DetailsPage page, string inputId);

private:
	IndexPage getIndex();
	DetailsPage getDetails(string id);
	void saveAllToHtml();
	void displayIndexRaw();
	void displayIndexHtml();
	void displayDetailsRaw(string id);
	void displayDetailsHtml(string id);
	//star makes it a pointer
	ConsoleHelper* consoleHelper;
	DbHelper* dbHelper;

	string path_;
	string sqlFile_;

};

