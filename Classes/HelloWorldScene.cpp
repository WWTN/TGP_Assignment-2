#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

// Includes required for Pseudo Random Numbers
#include <cstdlib>
#include <ctime>


USING_NS_CC;

Asteroid* asteroids[4];
game_player* playerObj;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	// First, lets create our seed for the random number generator
	srand(time(NULL));
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	//Schedule Update for when needed


	// Init Asteroids
	for (int i = 0; i < 10; i++)
	{
		asteroids[i] = new Asteroid(i);
		addChild(asteroids[i]);
	}

	//	game_player obj;
	playerObj = new game_player;

	// init here
	game_Ship = (Sprite*)rootNode->getChildByName("game_Ship");
	shipSpeed = 2.0;

	visibleTarget = (Sprite*)rootNode->getChildByName("visibleTarget");
	Rect collisionBox;
	collisionBox.size = visibleTarget->getBoundingBox().size;


	// Create a custom event listener
	auto touchListener = EventListenerTouchOneByOne::create();

	// Assign the event methods to the event listener (known as callbacks)
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	/* For more information on the eventdispatcher mechanism (and how events in Cocos work in general) go to http://www.cocos2d-x.org/wiki/EventDispatcher_Mechanism */
	// Add the event listener to the event dispatcher
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


	startButton = static_cast<ui::Button*>(rootNode->getChildByName("temp_Go"));
	
	this->scheduleUpdate();
	
    return true;
}

void HelloWorld::update(float delta)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j != i) {
				if (asteroids[i]->HasCollidedWithAsteroid(asteroids[j]->GetBoundingBox()))
				{
					asteroids[i]->AsteroidBounce(asteroids[j]->GetVec(), asteroids[j]->GetPos());
					asteroids[j]->AsteroidBounce(asteroids[i]->GetVec(), asteroids[i]->GetPos());
				}
			}
		}
	}

	if (visibleTarget->getOpacity() > 0)
	{
		visibleTarget->setOpacity(visibleTarget->getOpacity() - 3);
	}

	game_Ship->setPosition((HelloWorld::game_Ship->getPosition() + (trajectory * shipSpeed)));

	if (playerObj->asteroidCollision)
	{
		if (shipSpeed > 0)
		{
			shipSpeed = shipSpeed - 0.1;
		}
		else if (shipSpeed < 0)
		{
			shipSpeed = 0;
		}
	}
	else
	{
		shipSpeed = shipSpeed + 0.05;

	}

	if (GameManager::sharedGameManager()->isGameLive)
	{

	}
}

bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	visibleTarget->setPosition(touch->getLocation());
	visibleTarget->setOpacity(255);
	collisionBox.origin = visibleTarget->getBoundingBox().origin;
	

	Vec2 touchPaths = visibleTarget->getPosition();

	trajectory = (Vec2(touchPaths - game_Ship->getPosition()));

	trajectory.normalize();
	shipSpeed = 2.0;

	return true;
}

void HelloWorld::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	targetingOnline = false;
}

void HelloWorld::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//if (targetingOnline){
	//	visibleTarget->setPosition(touch->getLocation());
	//}
}

void HelloWorld::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{

}