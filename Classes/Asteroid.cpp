#include "Asteroid.h"
#include "cocostudio\CocoStudio.h"

using namespace cocos2d;
// debug stuff
char array[10];

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

	// somethings up here, chris plz help crei
	_winSize = Director::getInstance()->getVisibleSize();

	this->setPosition(Vec2(_winSize.width, _winSize.height));
	this->setAnchorPoint(Vec2(_winSize.width / 2, _winSize.height / 2));
	this->scheduleUpdate();

	_sprite = Sprite::create("Asteroid.png");
	_rootNode->addChild(_sprite);
	_sprite->setPosition(_winSize.width/2, _winSize.height/2);
	return true;
}

void Asteroid::update(float deltaTime)
{
	_sprite->setPosition(_sprite->getPositionX() - 200 * deltaTime, _sprite->getPositionY() - 200 * deltaTime);

	CheckOutsideScreen();

	sprintf(array, "%f", _sprite->getPositionX());
	cocos2d::log(array);

	if (_outsideScreen == true)
	{
		Reset();
		_outsideScreen = false;
	}
	
}

void Asteroid::CheckOutsideScreen()
{
	if (_sprite->getPositionX() > (_winSize.width + 50.0f) || _sprite->getPositionY() > (_winSize.height + 50.0f))
	{
		_outsideScreen = true;
	}
	if (_sprite->getPositionY() < 0.0f || (_sprite->getPositionX() < 0.0f))
	{
		_outsideScreen = true;
	}
}

void Asteroid::Reset()
{
	_sprite->setPosition(_winSize.width/2, _winSize.height/2);
}

