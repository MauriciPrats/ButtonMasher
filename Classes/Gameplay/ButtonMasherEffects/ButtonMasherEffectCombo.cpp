#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectCombo.h"


ButtonMasherEffectCombo::ButtonMasherEffectCombo(float timeItLasts) {
	type = Enumerators::MashButtonType::Combo;
}


bool ButtonMasherEffectCombo::Update(float deltaTime) {
	return false;
}

bool ButtonMasherEffectCombo::Consume() {
	return true;
}

float ButtonMasherEffectCombo::getComboMultiplicationIncrease(){
	return 0.5f;
}

float ButtonMasherEffectCombo::getSpeedMultiplicationIncrease(){
	return 0.0f;
}