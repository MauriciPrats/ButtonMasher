
#include "Gameplay/CoinsCollectors/MovingLabel.h"
#include "Constants.h"
#include "Utils.h"

MovingLabel::MovingLabel(cocos2d::Node* parent,cocos2d::Vec2 position,int ammount){

	labelToMove = cocos2d::Label::create("+" + Utils::getInstance().to_string(ammount), "Bitmap.TTF", 15);
	labelToMove->setTextColor(Constants::getInstance().movingLabelColor);
	labelToMove->setPosition(position);
	parent->addChild(labelToMove);
	timeToDisappear = Constants::getInstance().movingLabelTimeToDisappear;
	timer = 0.0f;
}


bool MovingLabel::Update(float deltaTime){

	timer += deltaTime;
	if (timer > timeToDisappear){
		labelToMove->getParent()->removeChild(labelToMove);
		return true;
	}
	else{
		float ratio = timer / timeToDisappear;
		labelToMove->setOpacity((1.0f - ratio) * 255);
		labelToMove->setPosition(labelToMove->getPosition() + (Constants::getInstance().movingLabelSpeed* deltaTime));
	}
	return false;
}