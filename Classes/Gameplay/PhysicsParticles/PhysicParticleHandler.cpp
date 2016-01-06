#include "Gameplay\PhysicsParticles\PhysicParticleHandler.h"


PhysicParticleHandler::PhysicParticleHandler(){
	particles = std::vector<PhysicParticle*>(0);
	movingLabels = std::vector<MovingLabel*>(0);

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

	//Update Particles
	std::vector<PhysicParticle*>::iterator iterator = particles.begin();
	bool hasDeletedElement;
	while (iterator != particles.end()) {
		hasDeletedElement = false;
		if ((*iterator)->Update(deltaTime)) {
			PhysicParticle* effect = (*iterator);
			if (effect->HasBeenCollected()){
				//Spawn a the label
				MovingLabel* label = new MovingLabel(parent, effect->getPosition(), effect->getAmmountWorth());
				movingLabels.push_back(label);
			}
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

	//Update Labels
	std::vector<MovingLabel*>::iterator iterator2 = movingLabels.begin();
	while (iterator2 != movingLabels.end()) {
		hasDeletedElement = false;
		if ((*iterator2)->Update(deltaTime)) {
			MovingLabel* label = (*iterator2);
			iterator2 = movingLabels.erase(iterator2);
			hasDeletedElement = true;
			//Before the next increment we check if we have reached the end
			delete label;
			if (iterator2 == movingLabels.end()){ break; }
		}
		if (!hasDeletedElement){
			iterator2++;
		}
	}
}