#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectsHandler.h"
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectCombo.h"

ButtonMasherEffectsHandler::ButtonMasherEffectsHandler() {
	this->effects = new std::vector<ButtonMasherEffect*>(0);
	comboLabel = cocos2d::Label::create("", "Bitmap.TTF", 12);
	speedLabel = cocos2d::Label::create("", "Bitmap.TTF", 12);
	comboCount = 0;
	speedCount = 0;
	parent = nullptr;
	comboMul = 1.0f;
	speedMul = 1.0f;
}


void ButtonMasherEffectsHandler::Update(float deltaTime){
	std::vector<ButtonMasherEffect*>::iterator iterator = effects->begin();
	bool hasDeletedElement;
	while (iterator != effects->end()) {
		hasDeletedElement = false;
		if ((*iterator)->Update(deltaTime)) {
			ButtonMasherEffect* effect = (*iterator);
			removeEffect(effect);
			iterator = effects->erase(iterator);
			hasDeletedElement = true;
			//Before the next increment we check if we have reached the end
			delete effect;
			if (iterator == effects->end()){ break; }
		}
		if (!hasDeletedElement){
			iterator++;
		}
	}
}

void ButtonMasherEffectsHandler::Consume(){
	std::vector<ButtonMasherEffect*>::iterator iterator = effects->begin();
	bool hasDeletedElement;
	while (iterator != effects->end()) {
		hasDeletedElement = false;
		if ((*iterator)->Consume()) {
			ButtonMasherEffect* effect = (*iterator);
			removeEffect(effect);
			iterator = effects->erase(iterator);
			hasDeletedElement = true;
			//Before the next increment we check if we have reached the end
			delete effect;
			if (iterator == effects->end()){ break; }
		}
		if (!hasDeletedElement){
			iterator++;
		}
	}
}

void ButtonMasherEffectsHandler::removeEffect(ButtonMasherEffect* effect){
	if (effect->getType() == Enumerators::MashButtonType::Combo){
		comboCount--;
	}
	else if (effect->getType() == Enumerators::MashButtonType::Speeder){
		speedCount--;
	}
	updateLabels();
}

void ButtonMasherEffectsHandler::updateLabels(){
	std::string comboText = "";
	for (int i = 0; i < comboCount; ++i){
		comboText += "+";
	}
	comboLabel->setString(comboText);
	calculateComboMultiplicator();

	std::string speedText = "";
	for (int i = 0; i < speedCount; ++i){
		speedText += ">";
	}
	speedLabel->setString(speedText);
	calculateSpeederMultiplicator();
}

void ButtonMasherEffectsHandler::addEffect(ButtonMasherEffect* newEffect){
	this->effects->push_back(newEffect);
	if (newEffect->getType() == Enumerators::MashButtonType::Combo){
		comboCount++;
	}
	else if (newEffect->getType() == Enumerators::MashButtonType::Speeder){
		speedCount++;
	}
	updateLabels();
}

void ButtonMasherEffectsHandler::setParent(cocos2d::Node* parent){
	this->parent = parent;
	parent->addChild(comboLabel);
	parent->addChild(speedLabel);
}

void ButtonMasherEffectsHandler::setPosition(cocos2d::Vec2 position){
	this->position = position;
	comboLabel->setPosition(position + cocos2d::Vec2(-20, 40));
	speedLabel->setPosition(position + cocos2d::Vec2(20, 40));
}

void ButtonMasherEffectsHandler::calculateComboMultiplicator(){
	comboMul = 1.0f;
	for (int i = 0; i < effects->size(); ++i){
		comboMul+=effects->at(i)->getComboMultiplicationIncrease();
	}
}

void ButtonMasherEffectsHandler::calculateSpeederMultiplicator(){
	speedMul = 1.0f;
	for (int i = 0; i < effects->size(); ++i){
		speedMul += effects->at(i)->getSpeedMultiplicationIncrease();
	}
	
}