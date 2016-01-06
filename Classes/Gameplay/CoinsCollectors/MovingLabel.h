#pragma once

#include "cocos2d.h"

USING_NS_CC;

class MovingLabel
{

public:
	MovingLabel(cocos2d::Node* parent, cocos2d::Vec2 position,int ammount);
	bool Update(float deltaTime);

private:
	cocos2d::Label* labelToMove;
	float timeToDisappear;
	float timer;
};