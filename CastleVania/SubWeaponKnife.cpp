#include "SubWeaponKnife.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GiftBox.h"

SubWeaponKnife::SubWeaponKnife()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_KNIFE));
	setWidth(getGraphicsAssets()->getWidth(0, 0));
	setHeight(getGraphicsAssets()->getHeight(0, 0));
}


void SubWeaponKnife::onUpdate(float dt)
{
	
	//DebugOut((wchar_t*)L"%f %f\n", getWidth(), getHeight());
	if (PLAYER->getPlayerState() == PLAYER_STATE_ATTACK_SUBWEAPON && !getIsRender()) {
		setIsAllowUpdateRender(true, true);
		setDir(PLAYER->getDir());
		setAction(0);
		if (getDir() == RIGHT) {
			if (PLAYER->getFrame() == 2) {
				this->setX(PLAYER->getX() + 22);
				this->setY(PLAYER->getY() - 10);
				this->setFrame(0);
				setDx(4);
				setIsStopCollision(false);
				setIsRender(true);
			}
		}
		else {
			if (PLAYER->getFrame() == 2) {
				this->setX(PLAYER->getX() - 22 - getWidth());
				this->setY(PLAYER->getY() - 10);
				this->setFrame(0);
				setDx(-4);
				setIsStopCollision(false);
				setIsRender(true);
			}
		}
	}

	BaseObject::onUpdate(dt);
}

SubWeaponKnife::~SubWeaponKnife()
{
}
