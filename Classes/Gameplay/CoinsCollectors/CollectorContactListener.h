#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class CollectorContactListener : public cocos2d::EventListenerPhysicsContact
{
public:
	CollectorContactListener();
    bool onContactBegin(cocos2d::PhysicsContact& contact);

private:

};