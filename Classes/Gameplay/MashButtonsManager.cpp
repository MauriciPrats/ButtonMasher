

#include "Gameplay/MashButtonsManager.h"

MashButtonsManager::MashButtonsManager() {
	mashButtons = std::vector<MashButton*>(0);
}

void MashButtonsManager::registerMashButton(MashButton* mashButton) {
	this->mashButtons.push_back(mashButton);
}

void MashButtonsManager::updateButtons(float deltaTime) {
	for (int i = 0; i < mashButtons.size(); ++i) {
		mashButtons[i]->Update(deltaTime);
	}
}

MashButton* MashButtonsManager::createMashButton(Enumerators::MashButtonType type,cocos2d::Size size) {
	cocos2d::ui::Button* button = static_cast<cocos2d::ui::Button*>(buttonInstance->clone());
	button->setVisible(true);
	button->setContentSize(size);

	cocos2d::ui::LoadingBar* loadingBar = static_cast<cocos2d::ui::LoadingBar*>(loadingBarInstance->clone());
	loadingBar->setVisible(true);
	loadingBar->setContentSize(size);

	cocos2d::ParticleSystemQuad* particles = cocos2d::ParticleSystemQuad::create("particle_button_click.plist");
	particles->setContentSize(size * 0.5f);
	//particles->stopSystem();

	MashButton* mashButton;
	if (type == Enumerators::MashButtonType::Normal) {
		button->setTitleText("Normal");
		button->setColor(cocos2d::Color3B(200, 120, 120));
		particles->setStartColor(cocos2d::Color4F(1.0f, 1.0f, 1.0f,1.0f));
		particles->setScale(0.4f);
		mashButton = new MashButton(button, loadingBar,particles, Enumerators::MashButtonEffectType::Cross, Enumerators::MashButtonType::Normal,20,2);
	}else if (type == Enumerators::MashButtonType::Combo) {
		button->setTitleText("Combo");
		button->setColor(cocos2d::Color3B(120, 200, 120));
		particles->setStartColor(cocos2d::Color4F(1.0f, 1.0f, 1.0f, 1.0f));
		particles->setScale(0.4f);
		mashButton = new MashButton(button, loadingBar, particles, Enumerators::MashButtonEffectType::X, Enumerators::MashButtonType::Combo, 10, 3);
	}
	else if (type == Enumerators::MashButtonType::Speeder) {
		button->setTitleText("Speeder");
		button->setColor(cocos2d::Color3B(120, 120, 200));
		particles->setStartColor(cocos2d::Color4F(1.0f, 1.0f, 1.0f, 1.0f));
		particles->setScale(0.4f);
		mashButton = new MashButton(button, loadingBar, particles, Enumerators::MashButtonEffectType::Cross, Enumerators::MashButtonType::Speeder, 12, 2);
	}
	return mashButton;
}