#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectCombo.h"
#include "Constants.h"


ButtonMasherEffectCombo::ButtonMasherEffectCombo(float timeItLasts) {
	type = Enumerators::MashButtonType::Combo;
}


bool ButtonMasherEffectCombo::Update(float deltaTime) {
	return false;
}

bool ButtonMasherEffectCombo::Consume() {
	return Constants::getInstance().comboEffectEndOnConsume;
}

float ButtonMasherEffectCombo::getComboMultiplicationIncrease(){
	return Constants::getInstance().comboEffectComboMultiplicator;
}

float ButtonMasherEffectCombo::getSpeedMultiplicationIncrease(){
	return Constants::getInstance().comboEffectSpeedMultiplicator;
}