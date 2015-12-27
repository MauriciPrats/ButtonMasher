#pragma once

#include "Gameplay/MashButton.h"
#include "Enumerators.h"

class MashButtonsManager
{
public:

	static MashButtonsManager& getInstance(){
		static MashButtonsManager INSTANCE;
		return INSTANCE;
	}
	void registerMashButton(MashButton* mashButton);
	void updateButtons(float deltaTime);
	MashButton* createMashButton(Enumerators::MashButtonType type, cocos2d::Size size);
	void setButtonInstance(cocos2d::ui::Button* mashButton) { this->buttonInstance = mashButton; }
	void setLoadingBarInstance(cocos2d::ui::LoadingBar* loadingBarInstance) { this->loadingBarInstance = loadingBarInstance; }
private:
	cocos2d::ui::Button* buttonInstance;
	cocos2d::ui::LoadingBar* loadingBarInstance;
	std::vector<MashButton*> mashButtons;
	MashButtonsManager();
	MashButtonsManager(MashButtonsManager const&); // Don't Implement
	void operator=(MashButtonsManager const&); // Don't implement
};