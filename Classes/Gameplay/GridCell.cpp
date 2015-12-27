#include "Gameplay/GridCell.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "DragAndDrop/DraggableItem.h"
#include "Gameplay/MashButtonsManager.h"

GridCell::GridCell(cocos2d::Color3B color, int row, int col, cocos2d::Vec2 pos, float width, float height, cocos2d::Node* parent) {
	sprite = cocos2d::ui::Scale9Sprite::create("ButtonBackground.png");
	sprite->setColor(color);
	sprite->setContentSize(cocos2d::Size(width, height));
	sprite->setPosition(pos);
	this->parent = parent;
	parent->addChild(sprite);
	originalColor = color;
	this->posx = col;
	this->posy = row;
}


bool GridCell::containsPoint(cocos2d::Vec2 point) {
	return sprite->getBoundingBox().containsPoint(point - parent->getPosition());
}
void GridCell::onDragOver() {
	if (!hasItemDragged) {
		sprite->setColor(Color3B(100, 255, 100));
	}
	else {
		sprite->setColor(Color3B(255, 100, 100));
	}
}
void GridCell::onNoDragOver() {
	sprite->setColor(originalColor);
}

bool GridCell::setDraggedItem(DraggableItem* newDraggableItem) {
	//cocos2d::ui::Button* buttonCreated = static_cast< cocos2d::ui::Button*>(newDraggableItem->getButton()->clone());
	//parent->getParent()->addChild(buttonCreated);

	//buttonCreated->setPosition(parent->convertToWorldSpace(sprite->getPosition()));
	this->mashButton = MashButtonsManager::getInstance().createMashButton(newDraggableItem->getType(),sprite->getContentSize());
	this->mashButton->setParent(parent->getParent(),posx,posy);
	this->mashButton->setPosition(parent->convertToWorldSpace(sprite->getPosition()));
	hasItemDragged = true;
	onNoDragOver();
	return false;
}

bool GridCell::canDropItem() {
	return !hasItemDragged;
}

bool GridCell::canGrabItem() {
	return true;
}