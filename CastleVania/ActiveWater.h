#pragma once
#include "BaseObject.h"
class ActiveWater :
	public BaseObject
{
public:
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	ActiveWater();
	~ActiveWater();
};

