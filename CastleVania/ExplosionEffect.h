#pragma once
#include "BaseObject.h"
#include"DelayTime.h"
class ExplosionEffect :
	public BaseObject
{
	static ExplosionEffect* instance;
public:
	DelayTime effectDelay;
	static ExplosionEffect* getInstance();
	void onUpdate(float dt) override;
	ExplosionEffect();
	~ExplosionEffect();
};

