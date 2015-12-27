#include "Gameplay/MashButton.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Gameplay/GameManager.h"
#include "Gameplay/User.h"
#include "Gameplay/MashButtonsManager.h"
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectCombo.h"
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffectSpeeder.h"
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffect.h"


MashButton::MashButton(cocos2d::ui::Button* button,cocos2d::ui::LoadingBar* loadingBar, cocos2d::ParticleSystemQuad* particles, Enumerators::MashButtonEffectType areaEffectType, Enumerators::MashButtonType effectType,int maxAccumulated,int ammountPerSecond) {
	this->areaEffectType = areaEffectType;
	this->effectType = effectType;
	this->loadingBar = loadingBar;
	this->ammountAccumulatedPerSecond = ammountPerSecond;
	this->maxAmmountToAccumulate = maxAccumulated;
	this->button = button;
	button->addTouchEventListener(CC_CALLBACK_2(MashButton::onButtonPressed, this));
	MashButtonsManager::getInstance().registerMashButton(this);
	ammountAccumulated = 0.0f;
	isOnCooldown = false;
	originalSize = button->getContentSize();
	this->particles = particles;
	particles->stopSystem();
	effects = new std::vector<ButtonMasherEffect*>(0);

}


void MashButton::onButtonPressed(Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		GameManager::getInstance().getMainUser()->addCoinsAccumulated(maxAmmountToAccumulate);
		particles->resetSystem();
		this->button->setEnabled(false);
		isOnCooldown = true;
		generateEffects();
	}
}

void MashButton::Update(float deltaTime) {
	applyEffects(deltaTime);
	if (isOnCooldown) {
		ammountAccumulated += (ammountAccumulatedPerSecond * deltaTime);
		float ratio = (ammountAccumulated / (float)maxAmmountToAccumulate);
		loadingBar->setPercent(ratio * 100);
		if (ammountAccumulated > maxAmmountToAccumulate) {
			ammountAccumulated = 0.0f;
			this->button->setEnabled(true);
			isOnCooldown = false;
		}
	}
}

void MashButton::setParent(cocos2d::Node* parent, int posX, int posY) {
	parent->addChild(button);
	parent->addChild(loadingBar);
	parent->addChild(particles,1);
	this->parent = parent;
	this->posx = posX;
	this->posy = posY;
}

void MashButton::setPosition(cocos2d::Vec2 position) {
	button->setPosition(position);
	loadingBar->setPosition(position); 
	particles->setPosition(position);
}

void MashButton::applyEffects(float deltaTime) {
	std::vector<ButtonMasherEffect*>::iterator iterator = effects->begin();
	while (iterator != effects->end()) {
		if ((*iterator)->Update(deltaTime)) {
			ButtonMasherEffect* effect = (*iterator);
			iterator = effects->erase(iterator);
			delete effect;
		}
		iterator++;
	}
}

void MashButton::consumeEffects() {
	std::vector<ButtonMasherEffect*>::iterator iterator = effects->begin();
	while (iterator != effects->end()) {
		if ((*iterator)->Consume()) {
			ButtonMasherEffect* effect = (*iterator);
			iterator = effects->erase(iterator);
			delete effect;
		}
		iterator++;
	}
}

void MashButton::addEffect(ButtonMasherEffect* effect) {
	effects->push_back(effect); 
	effect->setParentAndPosition(parent, parent->convertToWorldSpace(particles->getPosition()));
}

void MashButton::generateEffects() {
	Grid* grid = GameManager::getInstance().getMainUser()->getGrid();
	std::vector<GridCell*>* cells;
	ButtonMasherEffect* effect;
	
	bool hasAreaType = false;
	bool hasType = false;
	if (effectType == Enumerators::MashButtonEffectType::Area) {
		cells = grid->getGridCellsInCircle(posx, posy, false, 1);
		hasAreaType = true;
	}
	else if (effectType == Enumerators::MashButtonEffectType::Cross) {
		cells = grid->getGridCellsInCross(posx, posy, false, 1);
		hasAreaType = true;
	}
	else if (effectType == Enumerators::MashButtonEffectType::X) {
		cells = grid->getGridCellsInX(posx, posy, false, 1);
		hasAreaType = true;
	}

	for (int i = 0; i < cells->size(); ++i) {
		if (cells->at(i)->hasMashButton()) {
			if (hasAreaType) {
				if (effectType == Enumerators::MashButtonType::Combo) {
					effect = new ButtonMasherEffectCombo(1.0f);
					hasType = true;
				}
				else if (effectType == Enumerators::MashButtonType::Speeder) {
					effect = new ButtonMasherEffectSpeeder(1.0f);
					hasType = true;
				}
				if (hasType) {
					cells->at(i)->getMashButton()->addEffect(effect);
				}
			}
		}
	}
	
}