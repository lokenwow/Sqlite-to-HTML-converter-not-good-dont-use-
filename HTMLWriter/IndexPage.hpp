#pragma once
#include "DbEntry.hpp"
#include "Page.hpp"

class IndexPage : public Page
{
public:
	IndexPage();

	void addEntry(DbEntry dbEntry);
private:
};

