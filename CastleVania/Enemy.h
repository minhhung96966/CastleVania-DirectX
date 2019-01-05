#pragma once
#include "BaseObject.h"
class Enemy :
	public BaseObject
{
	bool isPreviousTriggerMorningStar;
public:
	void setIsPreviousTriggerMorningStar(bool isPreviousTriggerMorningStar);
	bool getIsPreviousTriggerMorningStar();
	virtual void setDirectionToPlayer();
	virtual void onHitByWeapon();
	void onIntersection(BaseObject* other) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	void render(Camera* camera) override;
	void onUpdate(float dt) override;

	void onReborn() override;
	

	Enemy();
	~Enemy();
};

