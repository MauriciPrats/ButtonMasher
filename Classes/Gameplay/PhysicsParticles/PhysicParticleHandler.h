#pragma once

#include "cocos2d.h"
#include "Gameplay\PhysicsParticles\PhysicParticle.h"
#include "Gameplay\CoinsCollectors\MovingLabel.h"

USING_NS_CC;

class PhysicParticleHandler
{

public:
	PhysicParticleHandler();
	void createPhysicParticles(int coins);
	void setParent(cocos2d::Node* parent);
	void setPosition(cocos2d::Vec2 position);
	void Update(float deltaTime);

private:
	cocos2d::Node* parent;
	cocos2d::Vec2 position;
	std::vector<MovingLabel*> movingLabels;
	std::vector<PhysicParticle*> particles;
};