#pragma once
#include <string>
using namespace std;
class DbEntry
{

/*  contacts
        first_name
        last_name
        email
        countrycode
        id
        catagory

    countries
        code_
        filename_
        flag_png_
        name_
*/

public:
	string id_;
	string firstName_;
	string lastName_;
    string email_;
    string countrycode_;
    string catagory_;
    string code_;
    string filename_;
    string flag_png_;
    string name_;

	DbEntry(
        string id
        , string firstName
        , string lastName
        , string email
        , string countrycode
        , string catagory
        , string code
        , string filename
        , string flag_png
        , string name
        );
    DbEntry(
        string id
    );
    
private:


};

