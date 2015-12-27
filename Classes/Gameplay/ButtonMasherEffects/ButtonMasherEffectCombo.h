#pragma once
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffect.h"

class ButtonMasherEffectCombo : public ButtonMasherEffect {

public:
	ButtonMasherEffectCombo(float timeItLasts);
	virtual bool Update(float deltaTime);
	virtual bool Consume();
	virtual void setParentAndPosition(cocos2d::Node* parent, cocos2d::Vec2 position);

private:
	cocos2d::Label* label;
	float timeToFadeOut = 3.5f;
	float timeAccumulated = 0.0f;
	cocos2d::Vec2 speed;
};