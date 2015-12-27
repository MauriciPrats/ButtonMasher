#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectSpeeder.h"


ButtonMasherEffectSpeeder::ButtonMasherEffectSpeeder(float timeItLasts) {
	label = cocos2d::Label::create(">>>", "Bitmap.TTF", 15);
	speed = cocos2d::Vec2(((float)cocos2d::RandomHelper::random_int(-1000, 1000)) / 1000, 1)*10.0f;
}


bool ButtonMasherEffectSpeeder::Update(float deltaTime) {
	timeAccumulated += deltaTime;
	if (timeAccumulated < timeToFadeOut) {
		int alpha = 255 - (255 * (timeAccumulated / timeToFadeOut));
		if (alpha < 0) { alpha = 0; }
		label->setTextColor(cocos2d::Color4B(100, 100, 250, alpha));
		label->enableGlow(cocos2d::Color4B(255, 255, 255, alpha));
		label->setPosition(label->getPosition() + (speed * deltaTime));
	}

	return false;
}

bool ButtonMasherEffectSpeeder::Consume() {
	label->getParent()->removeChild(label);
	delete label;
	return true;
}

void ButtonMasherEffectSpeeder::setParentAndPosition(cocos2d::Node* parent, cocos2d::Vec2 position) {
	parent->addChild(label);
	label->setPosition(position);
	label->setPosition(label->getPosition() + (speed*2.0f));
}