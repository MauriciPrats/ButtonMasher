#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Gameplay/User.h"

USING_NS_CC;

class GameManager
{
public:
	static GameManager& getInstance()
	{
		static GameManager INSTANCE;
		return INSTANCE;
	}

	void setMainUser(User* user) {this->mainUser = user; }
	User* getMainUser() { return mainUser; }
private:
	User* mainUser;
	GameManager();
	GameManager(GameManager const&);	// Don't Implement
	void operator=(GameManager const&); // Don't implement
};