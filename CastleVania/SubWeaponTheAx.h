#pragma once
#include "SubWeapon.h"
class SubWeaponTheAx :
	public SubWeapon
{
public:
	void onUpdate(float dt) override;
	SubWeaponTheAx();
	~SubWeaponTheAx();
};

