#pragma once

#include "cocos2d.h"
#include "DragAndDrop/DraggableItem.h"

class DroppableItem
{
public:
	DroppableItem();
	virtual bool containsPoint(cocos2d::Vec2 point) = 0;
	virtual void onDragOver() = 0;
	virtual void onNoDragOver() = 0;

	virtual bool canDropItem() = 0;
	virtual bool canGrabItem() = 0;
	virtual bool setDraggedItem(DraggableItem* newDraggableItem) = 0;

protected:
	bool hasItemDragged;
};