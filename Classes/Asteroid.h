#pragma once

#include "HelloWorldScene.h"
#include "cocos2d.h"

class Asteroid : public cocos2d::Node
{
public:
	// Object Constructors
	Asteroid();
	~Asteroid();
	static Asteroid* create();
	virtual bool init() override;

	// Update
	virtual void update(float);

	// Collision Detection
	void CheckOutsideScreen();

	// Movement
	void Reset();
	cocos2d::Vec2 CreateStartPoint();
	void CreateEndPoint(float start);
	

private:
	// Asteroid Variables
	bool  _outsideScreen;
	float _rotation;
	float _speed;
	int   _randStart;
	float _randEnd;

	// Cocos Variables
	cocos2d::Sprite* _sprite;
	cocos2d::Node*	 _rootNode;
	cocos2d::Size	 _winSize;
	cocos2d::Vec2	 _start;
	cocos2d::Vec2	 _endPoint;
	cocos2d::Vec2	 _startpoints[8];
	cocos2d::Vec2    _currentPoint;
	cocos2d::Vec2    _trajectory;
};

