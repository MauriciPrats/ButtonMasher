
#include "DragAndDrop/DroppablesManager.h"


DroppablesManager::DroppablesManager() {
	droppableItems = std::vector<DroppableItem*>(0);
}

void DroppablesManager::registerDroppableItem(DroppableItem* newDroppableItem) {
	droppableItems.push_back(newDroppableItem);
}

void DroppablesManager::draggingItemOver(cocos2d::Vec2 position) {
	for (int i = 0; i < droppableItems.size(); ++i) {
		if (droppableItems[i]->containsPoint(position)) {
			droppableItems[i]->onDragOver();
		}
		else {
			droppableItems[i]->onNoDragOver();
		}
	}
}

bool DroppablesManager::dropItem(DraggableItem* item, cocos2d::Vec2 position) {
	for (int i = 0; i < droppableItems.size(); ++i) {
		if (droppableItems[i]->containsPoint(position) && droppableItems[i]->canDropItem()) {
			bool dragged = droppableItems[i]->setDraggedItem(item);
			return dragged;
		}
	}
	return false;
}
