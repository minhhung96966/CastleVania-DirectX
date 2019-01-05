#pragma once
#include "BaseObject.h"

#define MAX(a,b) a>b? a:b
#define MIN(a,b) a>b? b:a

#include<iostream>
using namespace std;

class Collision
{
public:
	
	static BaseObject* GetSweptBroadPhaseBox(BaseObject* box);

	
	static bool AABBCheck(BaseObject* M, BaseObject* S);

	
	static float SweptAABB(BaseObject* M, BaseObject* S, float &normalx, float &normaly);


	static void CheckCollision(BaseObject* M, BaseObject* S);

	Collision();
	~Collision();
};

