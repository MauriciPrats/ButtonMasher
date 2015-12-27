#pragma once
#include "cocos2d.h"

class ButtonMasherEffect {
	public:
		virtual bool Update(float deltaTime) = 0;
		virtual bool Consume() = 0;
		virtual void setParentAndPosition(cocos2d::Node* parent,cocos2d::Vec2 position) = 0;
};