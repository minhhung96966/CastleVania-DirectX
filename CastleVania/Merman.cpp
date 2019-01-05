#include "Merman.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"
#include "MermanBullet.h"
#include "Camera.h"
#include "Water.h"

Merman::Merman()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_MERMAN));
	setPhysicsEnable(false);
	setIsAllowUpdateRender(true, false);
	setMermanState(MERMAN_STATE_JUMP);
	runDelay.init(1500);
	fireDelay.init(500);
	setHeight(MERMAN_RUN_HEIGHT);
}

void Merman::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
	setAction(MERMAN_ACTION_JUMP);
}

void Merman::setAction(int action)
{
	BaseObject::setAction(getDir()*MERMAN_ACTION_COUNT + action);
}

void Merman::onReborn()
{
	Enemy::onReborn();
	setPhysicsEnable(false);
	setDx(0);
	setDy(0);
	setVx(0);
	setVy(0);
	setIsAllowUpdateRender(true, false);
	setMermanState(MERMAN_STATE_JUMP);
	setIsGrounded(false);
	setHeight(MERMAN_RUN_HEIGHT);
}

void Merman::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (ny == 1)
	{
		if (other == PLAYER) return;
		BaseObject::onCollision(other, collisionTime, nx, ny);
	}
}

void Merman::setMermanState(MERMAN_STATE mermanState)
{
	this->mermanState = mermanState;
}

MERMAN_STATE Merman::getMermanState()
{
	return this->mermanState;
}

void Merman::onUpdate(float dt)
{
	switch (mermanState) {
		case MERMAN_STATE_JUMP:
			setDirectionToPlayer();
			setAction(MERMAN_ACTION_JUMP);
			if (
				(PLAYER->getY() - this->getY() <= DISTANCE_Y_PLAYER_MERMAN)
				&& (this->getY() <= MERMAN_Y_IN_WATER)
				&& (abs(PLAYER->getMidX() - this->getMidX()) <= DISTANCE_X_PLAYER_MERMAN)
			)
			{
				setIsAllowUpdateRender(true, true);
				setVy(MERMAN_VY_JUMP);
				setPhysicsEnable(true);
			}
			if (this->isGrounded()) {
				runDelay.start();
				setMermanState(MERMAN_STATE_RUN);
				setAction(MERMAN_ACTION_RUN);
			}
			break;

		case MERMAN_STATE_RUN:
			runDelay.update();
			if (getDir() == LEFT)
				setVx(-MERMAN_VX);
			else
				setVx(MERMAN_VX);
			
			if (runDelay.isTerminated()) {
				fireDelay.start();
				setMermanState(MERMAN_STATE_FIRE);
				setHeight(MERMAN_FIRE_HEIGHT);
				setY(getY() - MERMAN_RUN_HEIGHT + MERMAN_FIRE_HEIGHT);
				MermanBullet* mermanBullet = new MermanBullet();
				mermanBullet->setDir(getDir());
				if (mermanBullet->getDir() == LEFT) {
					mermanBullet->setX(this->getX());
					mermanBullet->setY(this->getY() - 7);
				}
				else {
					mermanBullet->setX(this->getX() + this->getWidth());
					mermanBullet->setY(this->getY() - 7);
				}
			}
			break;

		case MERMAN_STATE_FIRE:
			fireDelay.update();
			setVx(0);
			setDx(0);
			setAction(MERMAN_ACTION_FIRE);

			if (fireDelay.isTerminated()) {
				runDelay.start();
				setMermanState(MERMAN_STATE_RUN);
				setHeight(MERMAN_RUN_HEIGHT);
				setY(getY() + MERMAN_RUN_HEIGHT - MERMAN_FIRE_HEIGHT);
				setDirectionToPlayer();
				setAction(MERMAN_ACTION_RUN);
			}

			break;
	}

	BaseObject::onUpdate(dt);
}


Merman::~Merman()
{
}
