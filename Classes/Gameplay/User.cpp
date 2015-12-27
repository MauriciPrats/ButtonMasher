#include "Gameplay/User.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"


User::User(long idUser, cocos2d::ui::Text* coinsAccumulatedText, cocos2d::ui::Text* levelText, Grid* grid) {
	this->grid = grid;
	this->idUser = idUser;
	this->coinsAccumulated = 0;
	this->expAccumulated = 0;

	this->coinsAccumulatedText = coinsAccumulatedText;
	this->levelText = levelText;

	coinsAccumulatedText->setText("x");
	//TODO: Set level

}

void User::addCoinsAccumulated(int ammount) {
	this->coinsAccumulated += ammount;
	std::stringstream ss;
	ss << coinsAccumulated;
	std::string str = ss.str();
	this->coinsAccumulatedText->setText(str);
}