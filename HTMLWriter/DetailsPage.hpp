#pragma once
#include "DbEntry.hpp"
#include "Page.hpp"

class DetailsPage : public Page
{
public:
	DetailsPage(string title2);

	void addEntry(DbEntry dbEntry);
	void addBackBtn();
private:

};

