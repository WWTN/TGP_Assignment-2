#include "Asteroid.h"
#include "cocostudio\CocoStudio.h"

using namespace cocos2d;

Asteroid::Asteroid()
{
	this->init();
}


Asteroid::~Asteroid()
{
}

Asteroid* Asteroid::create()
{
	Asteroid* _asteroid = new Asteroid();
	if (_asteroid->init())
	{
		_asteroid->autorelease();
		return _asteroid;
	}
	else
	{
		CC_SAFE_DELETE(_asteroid);
		return nullptr;
	}
}

bool Asteroid::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto _rootNode = CSLoader::createNode("Asteroid.csb");
	addChild(_rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->setAnchorPoint(Vec2(winSize.width / 2, winSize.height / 2));
	this->scheduleUpdate();

	_sprite = Sprite::create("Asteroid.png");
	_rootNode->addChild(_sprite);
	_sprite->setPosition(winSize.width / 2, winSize.height / 2);
	return true;
}

void Asteroid::update(float deltaTime)
{
	_sprite->setPosition(_sprite->getPositionX() - 200 * deltaTime, _sprite->getPositionY() - 200 * deltaTime);

}