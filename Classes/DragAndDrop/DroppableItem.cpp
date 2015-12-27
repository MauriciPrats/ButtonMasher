
#include "DragAndDrop/DroppableItem.h"
#include "DragAndDrop/DroppablesManager.h"

DroppableItem::DroppableItem() {
	DroppablesManager::getInstance().registerDroppableItem(this);
	hasItemDragged = false;
}

