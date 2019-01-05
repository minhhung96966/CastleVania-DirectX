#include "SubWeaponHolyWater.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"


SubWeaponHolyWater::SubWeaponHolyWater()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_HOLYWATER));
	setPhysicsEnable(true);
	setWidth(getGraphicsAssets()->getWidth(0, 0));
	setHeight(getGraphicsAssets()->getHeight(0, 0));
	setAction(0);
	delayFireTime.init(1000);
	holyWaterState = HOLYWATER_STATE_NORMAL;
}

void SubWeaponHolyWater::onUpdate(float dt)
{

	switch (holyWaterState)
	{
		case HOLYWATER_STATE_NORMAL:
			if (isGrounded()) {
				delayFireTime.start();
				setAction(1);
				holyWaterState = HOLYWATER_STATE_FIRE;
			}
			else {
				if (PLAYER->getPlayerState() == PLAYER_STATE_ATTACK_SUBWEAPON && !getIsRender()) {
					setIsAllowUpdateRender(true, true);
					setDir(PLAYER->getDir());
					if (getDir() == RIGHT) {
						if (PLAYER->getFrame() == 2) {
							setAction(0);
							this->setX(PLAYER->getX() + 22);
							this->setY(PLAYER->getY() + 10);
							this->setFrame(0);
							setVx(VX_HOLYWATER);
							setVy(VY_HOLYWATER);
							setIsStopCollision(false);
							setIsRender(true);
						}
					}
					else {
						if (PLAYER->getFrame() == 2) {
							setAction(0);
							this->setX(PLAYER->getX() - 22 - getWidth());
							this->setY(PLAYER->getY() + 10);
							this->setFrame(0);
							setVx(-VX_HOLYWATER);
							setVy(VY_HOLYWATER);
							setIsStopCollision(false);
							setIsRender(true);
						}
					}
				}
				BaseObject::onUpdate(dt);
			}
			break;
		case HOLYWATER_STATE_FIRE:
			delayFireTime.update();
			setDx(0);
			setDy(0);
			setVx(0);
			setVy(0);
			if (delayFireTime.isTerminated()) {
				holyWaterState = HOLYWATER_STATE_INVISIBLE;
				setIsRender(false);
				setIsAllowUpdateRender(false, false);
				setIsStopCollision(true);
			}
			BaseObject::onUpdate(dt);
			break;
		case HOLYWATER_STATE_INVISIBLE:
			break;
		default:
			break;
	}
}

void SubWeaponHolyWater::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (other->getObjectTag() == OBJECT_TAG_GROUND)
	{
		if (ny == 1)
		{
			setIsGrounded(true);
		}
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
}

void SubWeaponHolyWater::setAction(int action)
{
	BaseObject::setAction(getDir()*2 + action);
}

SubWeaponHolyWater::~SubWeaponHolyWater()
{
}
