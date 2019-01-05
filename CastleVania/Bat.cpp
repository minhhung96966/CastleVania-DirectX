#include "Bat.h"
#include "GraphicsAssetsManager.h"
#include <string>
#include "Collision.h"
#include "Player.h"

Bat::Bat()
{
	
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_BAT));
	setPhysicsEnable(false);
	setIsAllowUpdateRender(true, false);
	invisibleDelay.init(1000);
	setBatState(BAT_STATE_INVISIBLE);
	setIsStopCollision(true);
}

void Bat::onInitFromFile(ifstream & fs, int mapHeight)
{
	BaseObject::onInitFromFile(fs, mapHeight);
	string name;
	int value;

	fs >> name >> value;
	setParam(name.c_str(), value);

	fs >> name >> value;
	setParam(name.c_str(), value);

	fs >> name >> value;
	setParam(name.c_str(), value);

	fs >> name >> value;
	setParam(name.c_str(), value);

	fs >> name >> value;
	setParam(name.c_str(), value);

	boxAreaActiveY = mapHeight - boxAreaActiveY;

	boxAreaActive.setX(boxAreaActiveX);
	boxAreaActive.setY(boxAreaActiveY);
	boxAreaActive.setWidth(boxAreaActiveWidth);
	boxAreaActive.setHeight(boxAreaActiveHeight);

}

void Bat::setParam(const char * name, int value)
{
	if (strcmp(name, "player_contact_direction") == 0) this->playerContactDirection = value;
	if (strcmp(name, "box_area_active_height") == 0) this->boxAreaActiveHeight = value;
	if (strcmp(name, "box_area_active_width") == 0) this->boxAreaActiveWidth = value;
	if (strcmp(name, "box_area_active_x") == 0) this->boxAreaActiveX = value;
	if (strcmp(name, "box_area_active_y") == 0) this->boxAreaActiveY = value;
}


void Bat::setAction(int action)
{
	BaseObject::setAction(getDir() + action);
}

BAT_STATE Bat::getBatState()
{
	return this->batState;
}

void Bat::setBatState(BAT_STATE batState)
{
	this->batState = batState;
}


void Bat::onUpdate(float dt)
{
	switch (batState) {
	case BAT_STATE_INVISIBLE:
		if (PLAYER->getDir() == playerContactDirection && Collision::AABBCheck(&boxAreaActive, PLAYER))
		{
			invisibleDelay.start();
			setBatState(BAT_STATE_WAIT);
			setDirectionToPlayer();
			setAction(0);
		}
		break;
	case BAT_STATE_WAIT:
		invisibleDelay.update();

		if (invisibleDelay.isTerminated())
		{
			setIsAllowUpdateRender(true, true);
			setIsStopCollision(false);
			setBatState(BAT_STATE_FLY);
			if (getDir() == LEFT) {
				setDx(-1);
			}
			else {
				setDx(1);
			}
		}
		break;
	case BAT_STATE_FLY:
		int d = 20; //bat_r

		alpha += 1;
		if (alpha >= 360)
		{
			alpha -= 360;
		}
		setY(getInitY() + d * sin(alpha * 0.1));

		break;
	}

	BaseObject::onUpdate(dt);
}

void Bat::onReborn()
{
	Enemy::onReborn();
	setDx(0);
	setIsAllowUpdateRender(true, false);
	setBatState(BAT_STATE_INVISIBLE);
	setIsStopCollision(true);
}

void Bat::onIntersection(BaseObject * other)
{
	Enemy::onIntersection(other);
	if (other == PLAYER && getIsAllowUpdate() && getIsAllowRender())
	{
		onReborn();
	}
}


Bat::~Bat()
{
}
