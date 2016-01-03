#include "Scenes/GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Gameplay/MashButton.h"
#include "Gameplay/Grid.h"
#include "Gameplay/User.h"
#include "Gameplay/GameManager.h"
#include "Data/DataManager.h"
#include "DragAndDrop/DraggableItem.h"
#include "Gameplay/MashButtonsManager.h"
#include "Gameplay/CoinsCollectors/CoinsCollector.h"
#include "Gameplay/CoinsCollectors/CollectorContactListener.h"
#include "Constants.h"
#include "Enumerators.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(cocos2d::Vec2(0.0f, -600.0f));
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("GameScene.csb");


	auto container = rootNode->getChildByName("ButtonMap");
	auto userCoinsText = static_cast< cocos2d::ui::Text*>(rootNode->getChildByName("ButtonPartsText"));
	auto levelText = static_cast< cocos2d::ui::Text*>(rootNode->getChildByName("LevelText"));

	auto normalButton = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("NormalButton"));
	DraggableItem* nb = new DraggableItem(1,normalButton, Enumerators::MashButtonType::Normal);
	

	auto comboButton = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("ComboButton"));
	DraggableItem* cb = new DraggableItem(2,comboButton, Enumerators::MashButtonType::Combo);


	auto speederButton = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("SpeederButton"));
	DraggableItem* sb = new DraggableItem(3,speederButton, Enumerators::MashButtonType::Speeder);

	auto patternButton = static_cast< cocos2d::ui::Button*>(rootNode->getChildByName("PatternButton"));
	MashButtonsManager::getInstance().setButtonInstance(patternButton);

	auto patternLoadingBar = static_cast< cocos2d::ui::LoadingBar*>(rootNode->getChildByName("PatternLoadingBar"));
	MashButtonsManager::getInstance().setLoadingBarInstance(patternLoadingBar);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener,this);

	CoinsCollector* c = new CoinsCollector("CollectorWall1", "CollectorWall2", "CollectorBottom", this, rootNode);

	int rowCount = 5;
	int columnsCount = 5;

	Grid* grid = new Grid(rowCount, columnsCount, container);

	User* user = new User(0,userCoinsText,levelText,grid);
	GameManager::getInstance().setMainUser(user);

	addChild(rootNode);

	//DBTest
	DataManager::getInstance();

	this->scheduleUpdate();

	return true;
}


void GameScene::update(float deltaTime) {
	MashButtonsManager::getInstance().updateButtons(deltaTime);
}

bool GameScene::onContactBegin(PhysicsContact& contact)
{
	if (contact.getShapeA()->getGroup() == Constants::getInstance().collectorsGroup && contact.getShapeB()->getGroup() == Constants::getInstance().physicParticlesGroup){
		PhysicParticle* p = static_cast<PhysicParticle*>(contact.getShapeB()->getBody()->getNode()->getUserObject());
		p->Collect();
	}
	else if (contact.getShapeA()->getGroup() == Constants::getInstance().physicParticlesGroup && contact.getShapeB()->getGroup() == Constants::getInstance().collectorsGroup){
		PhysicParticle* p = static_cast<PhysicParticle*>(contact.getShapeA()->getBody()->getNode()->getUserObject());
		p->Collect();
	}

	return true;
}