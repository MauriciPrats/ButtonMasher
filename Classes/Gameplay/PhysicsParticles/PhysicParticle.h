#pragma once

#include "cocos2d.h"

USING_NS_CC;

class PhysicParticle : public cocos2d::Ref
{

public:
	PhysicParticle(cocos2d::Vec2 position, cocos2d::Vec2 throwDirection, cocos2d::Node* parent,int ammountWorth);
	bool Update(float deltaTime);
	bool HasBeenCollected(){ return hasBeenCollected; }
	int getAmmountWorth(){ return ammountWorth; }
	void Collect();
	void Destroy();
	cocos2d::Vec2 getPosition(){ return sprite->getPosition(); }
private: 
	cocos2d::Sprite* sprite;
	cocos2d::PhysicsBody* body;
	float fadeOutTimer;
	float timeToFadeOut = 5.0f;
	bool hasBeenCollected;
	int ammountWorth;
};