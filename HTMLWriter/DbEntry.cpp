#include "DbEntry.hpp"

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


/**
* overloaded constuctor
*/
DbEntry::DbEntry(string id, string firstName, string lastName, string email, string countrycode, string catagory, string code, string filename, string flag_png, string name)
    : id_ { id }
    , firstName_ { firstName }
    , lastName_ { lastName }
    , email_{ email }
    , countrycode_{ countrycode }
    , catagory_{ catagory }
    , filename_{ filename }
    , flag_png_{ flag_png }
    , name_{ name }
{
}

/**
* overloaded constuctor
*/
DbEntry::DbEntry(string id)
    : id_ { id }
{
}
