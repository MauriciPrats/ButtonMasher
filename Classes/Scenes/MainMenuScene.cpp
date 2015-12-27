#include "Scenes/MainMenuScene.h"
#include "Scenes/GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Constants.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(Constants::getInstance().mainSceneName);
	auto exitButton = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName(Constants::getInstance().mainSceneExitButtonName));
	auto playButton = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName(Constants::getInstance().mainScenePlayButtonName));

	auto particlesExit = static_cast< cocos2d::ParticleSystemQuad*>(rootNode->getChildByName(Constants::getInstance().mainSceneParticlesExitButton));
	auto particlesPlay = static_cast< cocos2d::ParticleSystemQuad*>(rootNode->getChildByName(Constants::getInstance().mainSceneParticlesPlayButton));
	particlesExit->stopSystem();
	particlesPlay->stopSystem();

	exitButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::onExitButtonClicked, this));
	playButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::onPlayButtonClicked, this));

	addChild(rootNode);
	return true;
}

void MainMenuScene::onExitButtonClicked(Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		auto particles = static_cast< cocos2d::ParticleSystemQuad*>(rootNode->getChildByName(Constants::getInstance().mainSceneParticlesExitButton));
		particles->resetSystem();
	}
	else if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		CCDirector::sharedDirector()->end();
	}
}

void MainMenuScene::onPlayButtonClicked(Ref* pSender, cocos2d::ui::Widget::TouchEventType type) {
	if (type == cocos2d::ui::Widget::TouchEventType::BEGAN)
	{
		auto particles = static_cast< cocos2d::ParticleSystemQuad*>(rootNode->getChildByName(Constants::getInstance().mainSceneParticlesPlayButton));
		particles->resetSystem();
	}
	else if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto myScene = GameScene::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(Constants::getInstance().timeForTransition, myScene,Constants::getInstance().colorTransition));
	}
}