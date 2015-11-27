#pragma once

#include "HelloWorldScene.h"
#include "cocos2d.h"

class Asteroid : public cocos2d::Node
{
public:
	Asteroid(Vec2 start, Vec2 end);
	~Asteroid();

	static Asteroid* create();
	virtual bool init() override;
	virtual void update(float);
	void CheckOutsideScreen();
	void Reset();

private:
	// Asteroid Variables
	bool _outsideScreen;
	float _rotation;
	Vec2  _start;
	Vec2  _end;

	// Cocos Variables
	cocos2d::Sprite* _sprite;
	cocos2d::Node* _rootNode;
	cocos2d::Size _winSize;
};

