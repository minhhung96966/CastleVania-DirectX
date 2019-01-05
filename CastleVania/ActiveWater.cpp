#include "ActiveWater.h"
#include "Water.h"
#include "Player.h"
#include "ScoreBar.h"
#include "WorldChildManager.h"

ActiveWater::ActiveWater()
{
}

void ActiveWater::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (ny == 1) {
		Water* water1 = new Water();
		water1->setPhysicsEnable(true);
		water1->setX(other->getMidX());
		water1->setY(other->getBottom());
		water1->setVy(VY_WATER);
		Water* water2 = new Water();
		water2->setPhysicsEnable(true);
		water2->setX(other->getMidX());
		water2->setY(other->getBottom());
		water2->setVy(VY_WATER);
		water2->setVx(-VX_WATER);
		Water* water3 = new Water();
		water3->setPhysicsEnable(true);
		water3->setX(other->getMidX());
		water3->setY(other->getBottom());
		water3->setVy(VY_WATER);
		water3->setVx(VX_WATER);
	}
	else {
		Water* water1 = new Water();
		water1->setPhysicsEnable(true);
		water1->setX(other->getMidX());
		water1->setY(other->getY());
		water1->setVy(VY_WATER);
		Water* water2 = new Water();
		water2->setPhysicsEnable(true);
		water2->setX(other->getMidX());
		water2->setY(other->getY());
		water2->setVy(VY_WATER);
		water2->setVx(-VX_WATER);
		Water* water3 = new Water();
		water3->setPhysicsEnable(true);
		water3->setX(other->getMidX());
		water3->setY(other->getY());
		water3->setVy(VY_WATER);
		water3->setVx(VX_WATER);
	}


	if (other == PLAYER) {
		PLAYER->setIsAllowUpdateRender(true, false);
		SCOREBAR->setPlayerLife(SCOREBAR->getPlayerLife() - 1);
		PLAYER->deadActionTime.start();
		PLAYER->setIsUndying(true);
		PLAYER->setHeight(PLAYER_DEAD_HEIGHT);
		PLAYER->setY(PLAYER->getY() - PLAYER_NORMAL_HEIGHT + PLAYER_DEAD_HEIGHT);
		PLAYER->setAction(PLAYER_ACTION_DEAD);
		PLAYER->setPlayerState(PLAYER_STATE_DEAD);
	}
}

ActiveWater::~ActiveWater()
{
}
