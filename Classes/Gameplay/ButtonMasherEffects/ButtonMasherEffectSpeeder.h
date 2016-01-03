#pragma once
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffect.h"

class ButtonMasherEffectSpeeder : public ButtonMasherEffect {

public:
	ButtonMasherEffectSpeeder(float timeItLasts);
	virtual bool Update(float deltaTime);
	virtual bool Consume();
	virtual float getComboMultiplicationIncrease();
	virtual float getSpeedMultiplicationIncrease();
private:
	float timeToFadeOut = 3.5f;
	float timeAccumulated = 0.0f;
};