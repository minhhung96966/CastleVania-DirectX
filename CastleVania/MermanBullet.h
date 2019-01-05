#pragma once
#include "BaseObject.h"

class MermanBullet :
	public BaseObject
{
public:
	bool isRemove;
	void onIntersection(BaseObject* other) override;
	void onUpdate(float dt) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	MermanBullet();
	~MermanBullet();
};

