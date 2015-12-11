#pragma once
//
//
//
//
//
//

#ifndef __BaseLandscapeProject__game_Player__
#define __BaseLandscapeProject__game_Player__
#include "cocos2d.h"
#include <stdio.h>
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"


/////////////////////////////////////////////////////
class game_player : public cocos2d::Node
{
	/////////////////////////////////////////////////////
public:
	game_player();
	~game_player();

	 game_player* create();
	virtual bool init() override;
	 
	 virtual void         update(float);

	bool         asteroidCollision(cocos2d::Rect collisionBoxToCheck, Sprite* ship);
	void         reset();
	bool			touchActive;

//	bool withinBoundingBox( Sprite* ship, Sprite* target);

	///////////////////////////////////////////////////////
private:

	cocos2d::Sprite* game_Ship;

	float            currentXPosition;
	float            currentYPosition;
	float			targetXPosition;
	float			targetYPosition;
	float			currentSpeed;
	
};
#endif /* defined(_BaseLandscapeProject__game_Player__) */


