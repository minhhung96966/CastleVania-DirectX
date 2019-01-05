#pragma once
#include "Enemy.h"
#include "MermanBullet.h"
#include"DelayTime.h"

enum MERMAN_STATE {
	MERMAN_STATE_JUMP,
	MERMAN_STATE_RUN,
	MERMAN_STATE_FIRE
};

enum MERMAN_ACTION {
	MERMAN_ACTION_JUMP,
	MERMAN_ACTION_RUN,
	MERMAN_ACTION_FIRE,
	MERMAN_ACTION_COUNT
};

class Merman :
	public Enemy
{
	MERMAN_STATE mermanState;
	DelayTime runDelay;
	DelayTime fireDelay;
public:
	void setMermanState(MERMAN_STATE mermanState);
	MERMAN_STATE getMermanState();
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	void onReborn() override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny);
	Merman();
	~Merman();
};

