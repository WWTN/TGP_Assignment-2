#include "Asteroid.h"
#include "cocostudio\CocoStudio.h"

using namespace cocos2d;
// debug stuff
char array[10];

Asteroid::Asteroid(Vec2 start, Vec2 end)
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

	_winSize = Director::getInstance()->getVisibleSize();

	this->setPosition(0.0,0.0);
	this->setAnchorPoint(Vec2(_winSize.width/2, _winSize.height/2));
	this->scheduleUpdate();

	_sprite = Sprite::create("Asteroid.png");
	_rootNode->addChild(_sprite);
	_sprite->setPosition(_winSize.width +50, _winSize.height + 50);
	
	_rotation = 0;
	return true;
}

void Asteroid::update(float deltaTime)
{
	_sprite->setPosition(_sprite->getPositionX() - 200 * deltaTime, _sprite->getPositionY() - 200 * deltaTime);

	CheckOutsideScreen();

	sprintf(array, "%f", _sprite->getPositionY());
	cocos2d::log(array);

	_rotation = _rotation + 1;

	_sprite->setRotation(_rotation);
	
	if (_rotation == 360)
	{
		_rotation = 0;
	}

	if (_outsideScreen == true)
	{
		Reset();
		_outsideScreen = false;
	}
	
}

void Asteroid::CheckOutsideScreen()
{
	if (_sprite->getPositionX() > (_winSize.width + 80.0f) || _sprite->getPositionY() > (_winSize.height + 80.0f))
	{
		_outsideScreen = true;
	}
	if (_sprite->getPositionY() < -80.0f || (_sprite->getPositionX() < -80.0f))
	{
		_outsideScreen = true;
	}
}

void Asteroid::Reset()
{
	_sprite->setPosition(_winSize.width, _winSize.height);
}

//float lerp(float v0, float v1, float t)
//{

//}
