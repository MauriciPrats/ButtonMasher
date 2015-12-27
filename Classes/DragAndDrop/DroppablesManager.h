#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Gameplay/User.h"
#include "DragAndDrop/DroppableItem.h"
#include "DragAndDrop/DraggableItem.h"

USING_NS_CC;

class DroppablesManager
{
public:
	static DroppablesManager& getInstance()
	{
		static DroppablesManager INSTANCE;
		return INSTANCE;
	}

	void registerDroppableItem(DroppableItem* newDroppableItem);
	void draggingItemOver(cocos2d::Vec2 position);
	bool dropItem(DraggableItem* item, cocos2d::Vec2 position);
private:
	std::vector<DroppableItem*> droppableItems;
	User* mainUser;
	DroppablesManager();
	DroppablesManager(DroppablesManager const&);	// Don't Implement
	void operator=(DroppablesManager const&); // Don't implement
};