#include "DbHelper.hpp"

/**
* overloaded constuctor
*/
DbHelper::DbHelper(string path)
    :path{ path } 
{
    
}

/**
* recieves params to locate data
* 
* fills DbEntry entry with data from database
* 
* returns 0
*/
int callback(void* obj, int argc, char** argv, char** azColName) {

    DbHelper* dbh = static_cast<DbHelper*> (obj);

    DbEntry* entry = new DbEntry (argv[4], argv[0], argv[1], argv[2], argv[3], argv[5], argv[6], argv[7], argv[8], argv[9]);
    dbh->addToVector(*entry);

    return 0;
}

/**
* recieves DbEntry object
* 
* pushes DbEntry into data
*/
void DbHelper::addToVector(DbEntry e) {
    data.push_back(e);
}

/**
* declares a new database link
* provides a null pointer
* 
* create connection to file
* run select statment on db
* close connection
* 
* returns data
*/

vector<DbEntry> DbHelper::FetchAll()
{        
    //declare
    sqlite3 *db; 
    int instance;
    char** error = nullptr;

    //logic stuffs
    instance = sqlite3_open("contacts2021.db", &db); 
    sqlite3_exec(db, "SELECT * FROM contacts JOIN countries ON countries.code_ = contacts.countrycode", callback, this, error);
    sqlite3_close(db);

    return data;

}

/**
* declares a new database link
* provides a null pointer
*
* create connection to file
* run select statment on db
* close connection
*
* if data is empty creates new DbEntry which is invalid and returns it
* else return index 0 of data
*/
DbEntry DbHelper::FetchOne(string id)
{
    //declare
    sqlite3* db;
    int instance;
    char** error = nullptr;

    //logic stuffs
    instance = sqlite3_open("contacts2021.db", &db);
    string sql1 = "SELECT * FROM contacts JOIN countries ON countries.code_ = contacts.countrycode WHERE id = '" + id + "'";
    const char* sql2 = sql1.c_str();
    sqlite3_exec(db, sql2, callback, this, error);
    sqlite3_close(db);

    if (data.empty()) {
        DbEntry e("-1");
        return e;
    }
    else
        return data[0];
}

