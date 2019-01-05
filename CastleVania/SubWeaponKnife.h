#pragma once
#include "SubWeapon.h"
#include "DelayTime.h"

enum KNIFE_STATE {
	KNIFE_STATE_NORMAL,
	KNIFE_STATE_INVISIBLE
};

class SubWeaponKnife :
	public SubWeapon
{
public:
	void onUpdate(float dt) override;
	SubWeaponKnife();
	~SubWeaponKnife();
};

