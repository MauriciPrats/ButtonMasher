
#pragma once
#include "cocos2d.h"
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffect.h"

class ButtonMasherEffectsHandler {

public:
	ButtonMasherEffectsHandler();
	void Update(float deltaTime);
	void Consume();
	void addEffect(ButtonMasherEffect* newEffect);
	void setPosition(cocos2d::Vec2 position);
	void setParent(cocos2d::Node* parent);
	float getComboMultiplicator(){ return comboMul; }
	float getSpeederMultiplicator(){ return speedMul; }

private:

	cocos2d::Node* parent;
	cocos2d::Vec2 position;
	std::vector<ButtonMasherEffect*>* effects;

	int comboCount;
	int speedCount;

	float comboMul;
	float speedMul;

	cocos2d::Label* comboLabel;
	cocos2d::Label* speedLabel;

	void removeEffect(ButtonMasherEffect* effect);
	void updateLabels();
	void calculateComboMultiplicator();
	void calculateSpeederMultiplicator();
};