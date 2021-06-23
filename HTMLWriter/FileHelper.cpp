#include "FileHelper.hpp"


/**
* recieves 3 strings
* 
* creates new ofstream object
* 
* opens connection to file
* pushes code into object 
* closes connection
* 
* 
*/
void FileHelper::writeToDisk(string path, string fileName, string code)
{

	//const std::filesystem::directory_entry d{ L"C:\\users\\loken\\Desktop\\testfolder" };

	ofstream out;

	//createFolder(path);

	out.open(path + "/" + fileName, ofstream::out);
	out << code;
	out.close();
}

