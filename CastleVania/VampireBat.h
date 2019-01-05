#pragma once
#include "Enemy.h"
#include "DelayTime.h"
#include "Player.h"

enum BOSS_STATE
{
	BOSS_STATE_UNMOVED,
	BOSS_STATE_WAIT,
	BOSS_STATE_MOVE_FAST,
	BOSS_STATE_MOVE_SLOW
};

enum BOSS_ACTION
{
	BOSS_ACTION_WAIT,
	BOSS_ACTION_ACTIVE
};

class VampireBat :
	public Enemy
{
	BOSS_STATE bossState;
	DelayTime waitDelay;
	DelayTime moveFastDelay;
	DelayTime moveSlowDelay;
	float xDes, yDes;
	int health;
	static VampireBat* instance;
	DelayTime undyingDelayTime;
public:
	static VampireBat* getInstance();

	void onCollision(BaseObject* other, int nx, int ny, float collisionTime);
	void setBossState(BOSS_STATE bossState);
	void onUpdate(float dt) override;
	void calculateOtherPoint();
	void onDecreaseHealth();
	void onReborn() override;
	void preventGoOutsideCamera();
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	void onHitByWeapon() override;

	VampireBat();
	~VampireBat();
};

