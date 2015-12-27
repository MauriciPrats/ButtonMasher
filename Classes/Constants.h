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





};