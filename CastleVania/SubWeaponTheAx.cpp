#include "SubWeaponTheAx.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"

SubWeaponTheAx::SubWeaponTheAx()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_THEAX));
	setPhysicsEnable(true);
	setWidth(getGraphicsAssets()->getWidth(0, 0));
	setHeight(getGraphicsAssets()->getHeight(0, 0));
}


void SubWeaponTheAx::onUpdate(float dt)
{
	if (PLAYER->getPlayerState() == PLAYER_STATE_ATTACK_SUBWEAPON && !getIsRender()) {
		setIsAllowUpdateRender(true, true);
		setDir(PLAYER->getDir());
		setAction(0);
		if (getDir() == RIGHT) {
			if (PLAYER->getFrame() == 2) {
				this->setX(PLAYER->getX() + 22);
				this->setY(PLAYER->getY());
				this->setFrame(0);
				setVx(VX_THE_AX);
				setVy(VY_THE_AX);
				setIsStopCollision(false);
				setIsRender(true);
			}
		}
		else {
			if (PLAYER->getFrame() == 2) {
				this->setX(PLAYER->getX() - 22 - getWidth());
				this->setY(PLAYER->getY());
				this->setFrame(0);
				setVx(-VX_THE_AX);
				setVy(VY_THE_AX);
				setIsStopCollision(false);
				setIsRender(true);
			}
		}
	}


	BaseObject::onUpdate(dt);
}


SubWeaponTheAx::~SubWeaponTheAx()
{
}
