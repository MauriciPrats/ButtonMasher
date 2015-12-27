#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "DragAndDrop/DroppableItem.h"
#include "Gameplay/MashButton.h"

USING_NS_CC;

class GridCell : public DroppableItem
{

public:
	GridCell(cocos2d::Color3B color,int row,int col,cocos2d::Vec2 pos,float width,float height,cocos2d::Node* parent);
	bool containsPoint(cocos2d::Vec2 point);
	void onDragOver();
	void onNoDragOver();
	bool canDropItem();
	bool canGrabItem();
	bool setDraggedItem(DraggableItem* newDraggableItem);
	MashButton* getMashButton() {return mashButton;}
	bool hasMashButton() {return hasItemDragged;}

private:
	int posx;
	int posy;
	MashButton* mashButton;
	cocos2d::ui::Scale9Sprite* sprite;
	cocos2d::Node* parent;
	cocos2d::Color3B originalColor;
};