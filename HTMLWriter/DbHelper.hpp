#pragma once
#include <string>
#include <vector>
#include "DbEntry.hpp"
#include "sqlite3.h"
#include <iostream>

using namespace std;

class DbHelper
{

public:
	string path;
	DbHelper(string path);
	vector<DbEntry> FetchAll();
	DbEntry FetchOne(string id);
	friend int callback(void *NotUsed, int argc, char **argv, char **azColName);
	vector<DbEntry> data;

	void addToVector(DbEntry e);

private:

};

