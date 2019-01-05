#pragma once
#include "SubWeapon.h"
#include "DelayTime.h"

enum HOLYWATER_STATE {
	HOLYWATER_STATE_NORMAL,
	HOLYWATER_STATE_FIRE,
	HOLYWATER_STATE_INVISIBLE
};

class SubWeaponHolyWater :
	public SubWeapon
{
	DelayTime delayFireTime;
	HOLYWATER_STATE holyWaterState;
public:
	void onUpdate(float dt) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	void setAction(int action) override;
	SubWeaponHolyWater();
	~SubWeaponHolyWater();
};

