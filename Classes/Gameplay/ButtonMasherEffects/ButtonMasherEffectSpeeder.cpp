#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectSpeeder.h"
#include "Constants.h"


ButtonMasherEffectSpeeder::ButtonMasherEffectSpeeder(float timeItLasts) {
	type = Enumerators::MashButtonType::Speeder;
	timeAccumulated = 0.0f;
	timeToFadeOut = Constants::getInstance().speedEffectTimeToFadeOut;
}


bool ButtonMasherEffectSpeeder::Update(float deltaTime) {
	timeAccumulated += deltaTime;
	if (timeAccumulated >= timeToFadeOut) {
		return true;
	}
	
	return false;
}

bool ButtonMasherEffectSpeeder::Consume() {

	return Constants::getInstance().speedEffectEndOnConsume;
}

float ButtonMasherEffectSpeeder::getComboMultiplicationIncrease(){
	return Constants::getInstance().speedEffectComboMultiplicator;
}

float ButtonMasherEffectSpeeder::getSpeedMultiplicationIncrease(){
	return Constants::getInstance().speedEffectSpeedMultiplicator;
}