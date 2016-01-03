#include "Gameplay/CoinsCollectors/CoinsCollector.h"
#include "Constants.h"

CoinsCollector::CoinsCollector(std::string nameWall1, std::string nameWall2, std::string nameBottom,cocos2d::Node* parent,cocos2d::Node* rootNode){

	auto collectorWall1 = static_cast< cocos2d::ui::Scale9Sprite*>(rootNode->getChildByName(nameWall1));
	float rotation = collectorWall1->getRotation();
	collectorWall1->setRotation(0.0f);
	auto body1 = PhysicsBody::createBox(collectorWall1->getBoundingBox().size, PHYSICSBODY_MATERIAL_DEFAULT);
	collectorWall1->setPhysicsBody(body1);
	collectorWall1->setRotation(rotation);
	body1->setDynamic(false);
	body1->setGroup(Constants::getInstance().collidersGroup);

	parent->addChild(collectorWall1);

	auto collectorWall2 = static_cast< cocos2d::ui::Scale9Sprite*>(rootNode->getChildByName(nameWall2));
	rotation = collectorWall2->getRotation();
	collectorWall2->setRotation(0.0f);
	auto body2 = PhysicsBody::createBox(collectorWall2->getBoundingBox().size, PHYSICSBODY_MATERIAL_DEFAULT);
	collectorWall2->setPhysicsBody(body2);
	collectorWall2->setRotation(rotation);
	body2->setDynamic(false);
	body2->setGroup(Constants::getInstance().collidersGroup);

	parent->addChild(collectorWall2);

	auto collectorBottom = static_cast< cocos2d::ui::Scale9Sprite*>(rootNode->getChildByName(nameBottom));
	auto body3 = PhysicsBody::createBox(collectorBottom->getBoundingBox().size, PHYSICSBODY_MATERIAL_DEFAULT);
	body3->setDynamic(false);
	body3->setContactTestBitmask(0xFFFFFFFF);
	body3->setGroup(Constants::getInstance().collectorsGroup);
	collectorBottom->setPhysicsBody(body3);
	parent->addChild(collectorBottom);

}