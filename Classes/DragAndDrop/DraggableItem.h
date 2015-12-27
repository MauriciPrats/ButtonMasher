#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Enumerators.h"

class DraggableItem : public cocos2d::Ref
{
public:
	DraggableItem(int idDraggableItem,cocos2d::ui::Button* node, Enumerators::MashButtonType type);
	bool onTouchBegan(cocos2d::Touch* t, cocos2d::Event* e);
	void onTouchMoved(cocos2d::Touch* t, cocos2d::Event* e);
	void onTouchEnded(cocos2d::Touch* t, cocos2d::Event* e);
	void setPosition(cocos2d::Vec2 newPosition) { button->setPosition(newPosition); }
	cocos2d::ui::Button* getButton() { return button; }
	Enumerators::MashButtonType getType() { return type; }
private:
	Enumerators::MashButtonType type;
	int idDraggableItem;
	cocos2d::ui::Button* button;
	cocos2d::Vec2 startingPosition;
	bool isMoving = false;
};