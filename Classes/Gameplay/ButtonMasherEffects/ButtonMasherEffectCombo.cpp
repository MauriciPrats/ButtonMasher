#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectCombo.h"


ButtonMasherEffectCombo::ButtonMasherEffectCombo(float timeItLasts) {
	label = cocos2d::Label::create("+1", "CHILD.TTF", 25);
	speed = cocos2d::Vec2(((float)cocos2d::RandomHelper::random_int(-1000, 1000)) /1000,1)*10.0f;
}


bool ButtonMasherEffectCombo::Update(float deltaTime) {
	timeAccumulated += deltaTime;
	if (timeAccumulated < timeToFadeOut) {
		int alpha = 255 - (255 * (timeAccumulated / timeToFadeOut));
		if (alpha < 0) { alpha = 0; }
		label->setTextColor(cocos2d::Color4B(100, 250, 100, alpha));
		label->enableGlow(cocos2d::Color4B(255, 255, 255, alpha));
		label->setPosition(label->getPosition() + (speed * deltaTime));
	}

	return false;
}

bool ButtonMasherEffectCombo::Consume() {
	label->getParent()->removeChild(label);
	delete label;
	return true;
}

void ButtonMasherEffectCombo::setParentAndPosition(cocos2d::Node* parent, cocos2d::Vec2 position) {
	parent->addChild(label);
	label->setPosition(position);
	label->setPosition(label->getPosition() + (speed*2.0f));
}