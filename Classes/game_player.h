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



/////////////////////////////////////////////////////
class game_player : public cocos2d::Node
{
	/////////////////////////////////////////////////////
public:
	game_player();
	~game_player();
	virtual bool init() override;
	 game_player* create();

	 
	void         update(float);
	bool         asteroidCollision(cocos2d::Rect collisionBoxToCheck);
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


