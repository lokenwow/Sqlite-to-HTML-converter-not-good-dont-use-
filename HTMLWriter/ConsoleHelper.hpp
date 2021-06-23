#pragma once
#include <string>
#include <iostream>
#include "DbEntry.hpp"
#include <vector>
using namespace std;

class ConsoleHelper
{
public:
    void PrintMainMenu();
    void PrintElementMenu();
    int GetMenuInput(int lb, int hb);
    string GetIdInput();
    void PrintOneRaw(DbEntry e);
    void PrintHtmlCode(string html);
    void InvalidId();
    vector<string> createElement(); 
  
private:

};

