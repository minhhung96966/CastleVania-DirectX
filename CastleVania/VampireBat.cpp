#include "VampireBat.h"
#include "Camera.h"
#include "ScoreBar.h"
#include "ItemEndGame.h"

#define MAX(a,b) (a>b? a : b)
#define MIN(a,b) (a<b? a : b)

extern int getRandom(int start, int end);

VampireBat::VampireBat()
{
	waitDelay.init(BOSS_WAIT_TIME);
	undyingDelayTime.init(1000);
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_VAMPIREBAT));
	setIsAllowUpdateRender(true, true);
	setAction(BOSS_ACTION_WAIT);
	setBossState(BOSS_STATE_UNMOVED);
	setAy(BOSS_AY);
	setPhysicsEnable(true);
	instance = this;
}

VampireBat * VampireBat::instance = 0;
VampireBat * VampireBat::getInstance()
{
	return instance;
}

void VampireBat::onCollision(BaseObject * other, int nx, int ny, float collisionTime)
{
}

void VampireBat::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void VampireBat::onUpdate(float dt)
{
	float vx2 = 0, vy2 = 0;
	waitDelay.update();
	moveFastDelay.update();
	moveSlowDelay.update();
	undyingDelayTime.update();
	switch (bossState)
	{
	case BOSS_STATE_UNMOVED:
	{
		setDx(0);
		setVx(0);
		setDy(0);
		setVy(0);
		int distance = PLAYER->getX() - getX();
		if (distance > BOSS_DISTANCE_ACTIVE)
		{
			WORLD_CHILD_MANAGER->setCurrentWorldChild(5);
			setBossState(BOSS_STATE_WAIT);
			setAction(BOSS_ACTION_ACTIVE);
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -VAMPIRE_BAT_FAST_VX;
			}
			else
			{
				vx2 = VAMPIRE_BAT_FAST_VX;
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			waitDelay.start();
		}
		break;
	}
	case BOSS_STATE_WAIT:
		setDx(0);
		setDy(0);
		setVx(0);
		setVy(0);
		if (waitDelay.isTerminated())
		{
			setBossState(BOSS_STATE_MOVE_FAST);
			setAction(BOSS_ACTION_ACTIVE);
			DWORD moveFastDelayTime = getRandom(BOSS_MOVE_FAST_TIME_MIN, BOSS_MOVE_FAST_TIME_MAX);
			moveFastDelay.start(moveFastDelayTime);
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -VAMPIRE_BAT_FAST_VX;
			}
			else
			{
				vx2 = VAMPIRE_BAT_FAST_VX;
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			setVx(vx2);
			setVy(vy2);
		}
		break;
	case BOSS_STATE_MOVE_FAST:
	{
		if (getDx() < 0 && CAMERA->getLeft() > getX() + getDx())
		{
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -VAMPIRE_BAT_FAST_VX;
			}
			else
			{
				vx2 = VAMPIRE_BAT_FAST_VX;
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			setVx(vx2);
			setVy(vy2);
		}

		if (getDx() > 0 && CAMERA->getRight() < getRight() + getDx())
		{
			calculateOtherPoint();
			if (xDes < getX())
			{
				vx2 = -VAMPIRE_BAT_FAST_VX;
			}
			else
			{
				vx2 = VAMPIRE_BAT_FAST_VX;
			}
			vy2 = (vx2 * (yDes - getY()) / (xDes - getX()));
			setVx(vx2);
			setVy(vy2);
		}

		if (moveFastDelay.isTerminated())
		{
			waitDelay.start();
			setBossState(BOSS_STATE_MOVE_SLOW);
			DWORD moveSlowDelayTime = getRandom(BOSS_MOVE_SLOW_TIME_MIN, BOSS_MOVE_SLOW_TIME_MAX);
			moveSlowDelay.start(moveSlowDelayTime);
			calculateOtherPoint();
			setVx(0);
			setVy(0);
			if (xDes < getX())
			{
				setDx(-1);
			}
			else
			{
				setDx(1);
			}
			setDy(-(getDx() * (yDes - getY()) / (xDes - getX())));
			return;
		}

		preventGoOutsideCamera();
		Enemy::onUpdate(dt);
		break;
	}
	case BOSS_STATE_MOVE_SLOW:
		if (moveSlowDelay.isTerminated())
		{
			setBossState(BOSS_STATE_WAIT);
			waitDelay.start();
		}
		preventGoOutsideCamera();
		break;
	default:
		break;
	}
}

void VampireBat::calculateOtherPoint()
{
	if (getMidX() > PLAYER->getMidX() && getX() - CAMERA->getX() > 30)
	{
		xDes = CAMERA->getLeft();
	}
	else
	{
		xDes = CAMERA->getRight();
	}

	int yMin = PLAYER->getMidY() - 60;

	int yMax = PLAYER->getMidY();

	yDes = getRandom(yMin, yMax);
}

void VampireBat::onDecreaseHealth()
{
}

void VampireBat::onReborn()
{
	BaseObject::onReborn();
	setIsPreviousTriggerMorningStar(false);
	setBossState(BOSS_STATE_UNMOVED);
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(true);
}


void VampireBat::preventGoOutsideCamera()
{
	if ((getX() + getDx() < CAMERA->getLeft() && getDx() < 0) || (getRight() + getDx() > CAMERA->getRight() && getDx() > 0))
	{
		setDx(-getDx());
	}

	if ((getY() + getDy() > CAMERA->getTop() - 48 && getDy() > 0)
		|| (getBottom() + getDy() < CAMERA->getBottom() + 32 && getDy() < 0))
	{
		setDy(-getDy());
	}
}

void VampireBat::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
}

void VampireBat::onHitByWeapon()
{
	if (!undyingDelayTime.isOnTime())
	{
		undyingDelayTime.start();
		SCOREBAR->increaseBossHealth(-3);
		if (SCOREBAR->getBossHealth() <= 0)
		{
			Enemy::onHitByWeapon();
			ITEM_END_GAME->delayWaitTime.start();
		}
	}
}

VampireBat::~VampireBat()
{
}
