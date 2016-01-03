#include "Gameplay\PhysicsParticles\PhysicParticleHandler.h"


PhysicParticleHandler::PhysicParticleHandler(){
	particles = std::vector<PhysicParticle*>(0);

}

void PhysicParticleHandler::createPhysicParticles(int coins){
	//TEST
	for (int i = 0; i < coins / 2; ++i){
		PhysicParticle* physicParticle = new PhysicParticle(position, cocos2d::Vec2(cocos2d::RandomHelper::random_real(-100.0f, 100.0f),cocos2d::RandomHelper::random_real(100.0f, 400.0f)), parent,2);
		particles.push_back(physicParticle);
	}
}

void PhysicParticleHandler::setParent(cocos2d::Node* parent){
	this->parent = parent;
}

void PhysicParticleHandler::setPosition(cocos2d::Vec2 position){
	this->position = position;
}

void PhysicParticleHandler::Update(float deltaTime){
	std::vector<PhysicParticle*>::iterator iterator = particles.begin();
	bool hasDeletedElement;
	while (iterator != particles.end()) {
		hasDeletedElement = false;
		if ((*iterator)->Update(deltaTime)) {
			if ((*iterator)->HasBeenCollected()){
				//Spawn a number
				//TEST!
				Label* l = cocos2d::Label::create("+", "Bitmap.TTF", 15);
				l->setPosition((*iterator)->getPosition());
				parent->addChild(l);
			}
			PhysicParticle* effect = (*iterator);
			effect->Destroy();
			iterator = particles.erase(iterator);
			hasDeletedElement = true;
			//Before the next increment we check if we have reached the end
			delete effect;
			if (iterator == particles.end()){ break; }
		}
		if (!hasDeletedElement){
			iterator++;
		}
	}
}