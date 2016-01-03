#include "Gameplay/CoinsCollectors/CollectorContactListener.h"
#include "Gameplay/PhysicsParticles/PhysicParticle.h"
#include "Constants.h"


CollectorContactListener::CollectorContactListener(){

}

bool CollectorContactListener::onContactBegin(PhysicsContact& contact)
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