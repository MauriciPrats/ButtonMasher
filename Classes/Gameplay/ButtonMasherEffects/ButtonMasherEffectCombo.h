#pragma once
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffect.h"

class ButtonMasherEffectCombo : public ButtonMasherEffect {

public:
	ButtonMasherEffectCombo(float timeItLasts);
	virtual bool Update(float deltaTime);
	virtual bool Consume();
	virtual float getComboMultiplicationIncrease();
	virtual float getSpeedMultiplicationIncrease();
private:

};