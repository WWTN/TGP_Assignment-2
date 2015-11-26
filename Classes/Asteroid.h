#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"

class Asteroid : public cocos2d::Node
{
public:
	Asteroid();
	~Asteroid();

	static Asteroid* create();
	virtual bool init() override;
	virtual void update(float);
	void CheckOutsideScreen();
	void Reset();

private:
	bool _outsideScreen;
	cocos2d::Sprite* _sprite;
	cocos2d::Node* _rootNode;
	cocos2d::Size _winSize;
};

