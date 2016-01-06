

#include "Gameplay/MashButtonsManager.h"
#include "Constants.h"

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

	MashButton* mashButton;
	if (type == Enumerators::MashButtonType::Normal) {
		button->setTitleText("Normal");
		button->setColor(Constants::getInstance().normalButtonColor);
		mashButton = new MashButton(button, loadingBar, Enumerators::MashButtonEffectType::Cross, Enumerators::MashButtonType::Normal, Constants::getInstance().normalButtonMaxAccumulated, Constants::getInstance().normalButtonAmmountPerSecond);
	}else if (type == Enumerators::MashButtonType::Combo) {
		button->setTitleText("Combo");
		button->setColor(Constants::getInstance().comboButtonColor);
		mashButton = new MashButton(button, loadingBar, Enumerators::MashButtonEffectType::X, Enumerators::MashButtonType::Combo, Constants::getInstance().comboButtonMaxAccumulated, Constants::getInstance().comboButtonAmmountPerSecond);
	}
	else if (type == Enumerators::MashButtonType::Speeder) {
		button->setTitleText("Speeder");
		button->setColor(Constants::getInstance().speedButtonColor);
		mashButton = new MashButton(button, loadingBar, Enumerators::MashButtonEffectType::Cross, Enumerators::MashButtonType::Speeder, Constants::getInstance().speedButtonMaxAccumulated, Constants::getInstance().speedButtonAmmountPerSecond);
	}
	return mashButton;
}