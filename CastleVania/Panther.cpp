#include "Panther.h"
#include "Player.h"
#include "MorningStar.h"
#include "ExplosionEffect.h"
#include "ListGateInstance.h"
#include "ScoreBar.h"


void Panther::setAction(int action)
{
	BaseObject::setAction(getDir()*PANTHER_ACTION_COUNT + action);
}

void Panther::setState(PANTHER_STATE pantherState)
{
	this->pantherState = pantherState;
}

void Panther::onUpdate(float dt)
{
	switch (pantherState)
	{
	case PANTHER_STATE_STAND:
		setVx(0);
		setAction(PANTHER_ACTION_STAND);
		if (abs(PLAYER->getMidX() - this->getMidX()) < PANTHER_DETECT_PLAYER_DISTANCE)
		{
			setState(PANTHER_STATE_RUN);
		}
		break;
	case PANTHER_STATE_RUN:
		if (getDir() == LEFT) setVx(-PANTHER_VX); else setVx(PANTHER_VX);
		setAction(PANTHER_ACTION_RUN);
		if (currentGroundCollision != NULL && ((
			getLeft() < currentGroundCollision->getLeft()) && getDir() == LEFT ||
			(getRight() > currentGroundCollision->getRight() && getDir() == RIGHT)))
		{
			setVy(PANTHER_VY);
			setState(PANTHER_STATE_JUMP);
			currentGroundCollision = NULL;
		}
		break;
	case PANTHER_STATE_JUMP:
		if (isGrounded())
		{
			setState(PANTHER_STATE_RUN);
			setDirectionToPlayer();
		}
		setAction(PANTHER_ACTION_JUMP);
		break;
	default:
		break;
	}

	BaseObject::onUpdate(dt);
}

void Panther::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	currentGroundCollision = other;
	Enemy::onCollision(other, collisionTime, nx, ny);
}


Panther::Panther()
{
	setDir(LEFT);
	setState(PANTHER_STATE_STAND);
	setAction(PANTHER_ACTION_STAND);
	currentGroundCollision = 0;
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_PANTHER));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
}


Panther::~Panther()
{
}
