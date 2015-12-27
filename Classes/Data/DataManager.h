#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Data/sqlite3.h"

USING_NS_CC;

class DataManager
{
public:
	static DataManager& getInstance()
	{
		static DataManager INSTANCE;
		return INSTANCE;
	}

private:
	sqlite3* pdb;

	DataManager();
	DataManager(DataManager const&);	// Don't Implement
	void operator=(DataManager const&); // Don't implement
};