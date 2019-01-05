#include "MermanBullet.h"
#include "GraphicsAssetsManager.h"
#include "MermanBulletListInstance.h"
#include "Player.h"
#include "MorningStar.h"
#include "ScoreBar.h"

void MermanBullet::onIntersection(BaseObject * other)
{
	if (other == PLAYER &&
		!(PLAYER->getPlayerState() == PLAYER_STATE_DIE) &&
		!PLAYER->getIsUndying())
	{
		SCOREBAR->increaseHealth(-2);

		if (SCOREBAR->getHealth() <= 0)
		{
			SCOREBAR->setPlayerLife(SCOREBAR->getPlayerLife() - 1);
			PLAYER->deadActionTime.start();
			PLAYER->setIsUndying(true);
			PLAYER->setHeight(PLAYER_DEAD_HEIGHT);
			PLAYER->setY(PLAYER->getY() - PLAYER_NORMAL_HEIGHT + PLAYER_DEAD_HEIGHT);
			PLAYER->setAction(PLAYER_ACTION_DEAD);
			PLAYER->setPlayerState(PLAYER_STATE_DEAD);
			return;
		}

		//Khi player đang ở cầu thang mà chết thì chỉ chớp nháy
		if (PLAYER->getPlayerState() == PLAYER_STATE_ON_STAIR) {
			PLAYER->setIsUndying(true);
			PLAYER->flashEffectDelay.start();
		}
		else {
			if (PLAYER->getPlayerState() == PLAYER_STATE_SEAT) {
				PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
				PLAYER->setY(PLAYER->getY() + PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT);
			}
			PLAYER->setAction(PLAYER_ACTION_DIE);
			PLAYER->setPlayerState(PLAYER_STATE_DIE);
			if (PLAYER->getDir() == 0)
				PLAYER->setVx(-PLAYER_VX_DIE);
			else
				PLAYER->setVx(PLAYER_VX_DIE);
			PLAYER->setVy(PLAYER_VY_DIE);
		}
	}
	else if (other = MORNING_STAR) {
		isRemove = true;
	}
}

void MermanBullet::onUpdate(float dt)
{
	if (getDir() == LEFT) {
		setDx(-2);
	}
	else {
		setDx(2);
	}
}

void MermanBullet::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
}

MermanBullet::MermanBullet()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_MERMAN_BULLET));
	MermanBulletListInstance::getBulletList()->push_back(this);
	setWidth(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_MERMAN_BULLET)->getWidth(0, 0));
	setHeight(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_MERMAN_BULLET)->getHeight(0, 0));
	isRemove = false;
}

MermanBullet::~MermanBullet()
{
}

