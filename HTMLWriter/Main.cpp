#include "SqlToHmtl.hpp"

/*
* 
* Author Ross Hamilton
* 
* Verison 1256.7
*/

/**
* calls run from the sqlToHtml (starts the program)
*/
int main()
{
	//ignore the below text for grading, this is for a future version
	// 
	//make string,
	//	send string to method to "create folder" if folder exists > do nothing.
	//												if !exist (create it)
	//go on with your life.

	//set the params for the folder to save to and the filename of the database. (relative to project root folder)
	SqlToHtml sqlToHtml("SqlExport", "sql.file");

	
	//running "run();" on the object created previously.
	sqlToHtml.run();


}

