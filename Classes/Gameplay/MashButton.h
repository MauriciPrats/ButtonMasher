#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Gameplay/ButtonMasherEffects/ButtonMasherEffect.h"
#include "Enumerators.h"

USING_NS_CC;

class MashButton
{

public:
	MashButton(cocos2d::ui::Button* button, cocos2d::ui::LoadingBar* loadingBar, cocos2d::ParticleSystemQuad* particles, Enumerators::MashButtonEffectType areaEffectType, Enumerators::MashButtonType effectType, int maxAccumulated, int ammountPerSecond);
	void Update(float deltaTime);
	void setPosition(cocos2d::Vec2 position);
	cocos2d::ui::Button* getButton() { return button; }
	void setParent(cocos2d::Node* parent,int posX = 0,int posY = 0);
	void addEffect(ButtonMasherEffect* effect);
	void applyEffects(float deltaTime);
private:
	cocos2d::ui::Button* button;
	cocos2d::ui::LoadingBar* loadingBar;
	cocos2d::ParticleSystemQuad* particles;
	std::vector<ButtonMasherEffect*>* effects;

	cocos2d::Node* parent;
	int maxAmmountToAccumulate;
	int ammountAccumulatedPerSecond;
	cocos2d::Size originalSize;
	int posx;
	int posy;

	Enumerators::MashButtonEffectType areaEffectType;
	Enumerators::MashButtonType effectType;

	float ammountAccumulated;
	bool isOnCooldown;

	void onButtonPressed(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void applyEffects();
	void consumeEffects();

	void generateEffects();
};