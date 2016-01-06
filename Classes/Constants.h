#pragma once

#include "cocos2d.h"

class Constants
{
public:

static Constants& getInstance() {
	static Constants INSTANCE;
	return INSTANCE;
}

//Scenes
cocos2d::Color3B colorTransition = cocos2d::Color3B(0, 255, 255);
float timeForTransition = 0.5f;

//Names Of Main Scene Elements
std::string mainSceneName = "MainScene.csb";
std::string mainSceneExitButtonName = "exitButton";
std::string mainScenePlayButtonName = "playButton";
std::string mainSceneParticlesExitButton = "particlesExitButton";
std::string mainSceneParticlesPlayButton = "particlesPlayButton";


//** Physics
//Collision Groups
int physicParticlesGroup = -1;
int collidersGroup = -2;
int collectorsGroup = -3;

//Contact Test Bitmask
int contactTestBitmask = 0xFFFFFFFF;

//Gravity
cocos2d::Vec2 gravity = cocos2d::Vec2(0.0f, -600.0f);

//Combo Button 
cocos2d::Color3B comboButtonColor = cocos2d::Color3B(120, 200, 120);
float comboEffectComboMultiplicator = 0.5f;
float comboEffectSpeedMultiplicator = 0.0f;
bool comboEffectEndOnConsume = true;
std::string comboString = "+";
cocos2d::Vec2 positionOffsetCombo = cocos2d::Vec2(-20, 40);
int comboButtonMaxAccumulated = 10;
int comboButtonAmmountPerSecond = 3;

//Speed Button 
cocos2d::Color3B speedButtonColor = cocos2d::Color3B(120, 120, 200);
float speedEffectComboMultiplicator = 0.0f;
float speedEffectSpeedMultiplicator = 0.5f;
float speedEffectTimeToFadeOut = 3.5f;
bool speedEffectEndOnConsume = false;
std::string speedString = ">";
cocos2d::Vec2 positionOffsetSpeed = cocos2d::Vec2(20, 40);
int speedButtonMaxAccumulated = 12;
int speedButtonAmmountPerSecond = 2;

//Normal Button
cocos2d::Color3B normalButtonColor = cocos2d::Color3B(200, 120, 120);
int normalButtonMaxAccumulated = 20;
int normalButtonAmmountPerSecond = 5;

//Grid
int gridWidth = 5;
int gridHeight = 5;
float divisionBetweenGridTiles = 5.0f;
float sideOffset = 10.0f;
cocos2d::Color3B tileColor1 = cocos2d::Color3B(130, 130, 130);
cocos2d::Color3B tileColor2 = cocos2d::Color3B(170, 170, 170);
cocos2d::Color3B onDragCanDropColor = cocos2d::Color3B(100, 255, 100);
cocos2d::Color3B onDragCannotDropColor = cocos2d::Color3B(255, 100, 100);

//Particles on collect Materials
cocos2d::Vec2 movingLabelSpeed = cocos2d::Vec2(0.0f, 40.0f);
float movingLabelTimeToDisappear = 2.0f;
cocos2d::Color4B movingLabelColor = cocos2d::Color4B::YELLOW;

};