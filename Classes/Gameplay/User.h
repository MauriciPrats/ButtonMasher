#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Gameplay/Grid.h"

USING_NS_CC;

class User
{

public:
	User(long idUser, cocos2d::ui::Text* coinsAccumulatedText, cocos2d::ui::Text* levelText, Grid* grid);
	void addCoinsAccumulated(int ammount);
	Grid* getGrid() { return grid; }
private:
	long idUser;
	long coinsAccumulated;
	long expAccumulated;
	Grid* grid;

	cocos2d::ui::Text* coinsAccumulatedText;
	cocos2d::ui::Text* levelText;
};