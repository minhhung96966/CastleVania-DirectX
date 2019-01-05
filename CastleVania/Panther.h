#pragma once
#include "Enemy.h"
enum PANTHER_STATE
{
	PANTHER_STATE_STAND,
	PANTHER_STATE_RUN,
	PANTHER_STATE_JUMP
};

enum PANTHER_ACTION
{
	PANTHER_ACTION_STAND,
	PANTHER_ACTION_RUN,
	PANTHER_ACTION_JUMP,
	PANTHER_ACTION_COUNT
};
class Panther :
	public Enemy
{
	PANTHER_STATE pantherState;
	BaseObject* currentGroundCollision; //Ground dang va cham hien tai
public:
	void setAction(int action) override;
	void setState(PANTHER_STATE pantherState);
	void onUpdate(float dt) override;
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	Panther();
	~Panther();
};

