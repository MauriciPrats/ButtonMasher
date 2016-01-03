#include "Gameplay/PhysicsParticles/PhysicParticle.h"
#include "Constants.h"
#include "Gameplay/GameManager.h"


PhysicParticle::PhysicParticle(cocos2d::Vec2 position,cocos2d::Vec2 throwDirection,cocos2d::Node* parent,int ammountWorth){
	sprite = Sprite::create("PhysicParticle.png");
	sprite->setScale(0.5f);
	sprite->setUserObject(this);
	body = PhysicsBody::createBox(sprite->getBoundingBox().size, PhysicsMaterial(1.0f, 0.1f, 0.0f));
	body->setAngularVelocity(cocos2d::RandomHelper::random_real(-6.0, 6.0));
	body->setContactTestBitmask(0xFFFFFFFF);
	//set initial velocity of physicsBody
	body->setVelocity(throwDirection);
	body->setGroup(Constants::getInstance().physicParticlesGroup);

	sprite->setPosition(position);
	sprite->setPhysicsBody(body);

	parent->addChild(sprite);
	fadeOutTimer = 0.0f;
	hasBeenCollected = false;
	this->ammountWorth = ammountWorth;
}

bool PhysicParticle::Update(float deltaTime){
	fadeOutTimer += deltaTime;
	if (fadeOutTimer > timeToFadeOut){
		return true;
	}
	else{
		float ratio = fadeOutTimer / timeToFadeOut;
		sprite->setOpacity((1.0f - ratio) * 255);
	}
	return false;
}
void PhysicParticle::Destroy(){
	sprite->getParent()->removeChild(sprite);
}

void PhysicParticle::Collect(){
	if (!hasBeenCollected){
		fadeOutTimer = timeToFadeOut;
		GameManager::getInstance().getMainUser()->addCoinsAccumulated(ammountWorth);
		hasBeenCollected = true;
	}
}