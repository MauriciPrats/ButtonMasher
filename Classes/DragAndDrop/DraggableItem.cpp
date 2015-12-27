#include "DragAndDrop/DraggableItem.h"
#include "DragAndDrop/DroppablesManager.h"

DraggableItem::DraggableItem(int idDraggableItem, cocos2d::ui::Button* button, Enumerators::MashButtonType type) {
	this->type = type;
	this->button = button;
	this->idDraggableItem = idDraggableItem;
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(DraggableItem::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(DraggableItem::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(DraggableItem::onTouchEnded, this);

	button->getEventDispatcher()->addEventListenerWithFixedPriority(listener, idDraggableItem*-1);
}

bool DraggableItem::onTouchBegan(cocos2d::Touch* t, cocos2d::Event* e) { 
	if (button->getBoundingBox().containsPoint(t->getLocation())) {
		startingPosition = button->getPosition();
		button->setPosition(t->getLocation());
		isMoving = true;
	}
	return true;
}
void DraggableItem::onTouchMoved(cocos2d::Touch* t, cocos2d::Event* e) {
	if (isMoving) {
		button->setPosition(t->getLocation());
		DroppablesManager::getInstance().draggingItemOver(t->getLocation());
	}
}

void DraggableItem::onTouchEnded(cocos2d::Touch* t, cocos2d::Event* e) {
	if (isMoving) {
		bool dropItem = DroppablesManager::getInstance().dropItem(this, t->getLocation());
		if(!dropItem){
			setPosition(startingPosition);
		}
		isMoving = false;
	}
}


