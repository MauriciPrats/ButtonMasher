#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectSpeeder.h"


ButtonMasherEffectSpeeder::ButtonMasherEffectSpeeder(float timeItLasts) {
	type = Enumerators::MashButtonType::Speeder;
}


bool ButtonMasherEffectSpeeder::Update(float deltaTime) {
	timeAccumulated += deltaTime;
	if (timeAccumulated >= timeToFadeOut) {
		return true;
	}
	
	return false;
}

bool ButtonMasherEffectSpeeder::Consume() {

	return false;
}

float ButtonMasherEffectSpeeder::getComboMultiplicationIncrease(){
	return 0.0f;
}

float ButtonMasherEffectSpeeder::getSpeedMultiplicationIncrease(){
	return 0.5f;
}