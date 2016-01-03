#pragma once
#include "cocos2d.h"
#include "Enumerators.h"

class ButtonMasherEffect {
	public:
		virtual bool Update(float deltaTime) = 0;
		virtual bool Consume() = 0;
		virtual float getComboMultiplicationIncrease() = 0;
		virtual float getSpeedMultiplicationIncrease() = 0;

		Enumerators::MashButtonType getType(){ return type; }

	protected:
		Enumerators::MashButtonType type;

};