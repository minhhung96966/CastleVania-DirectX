#include "TeleportStair.h"
#include <string>
#include "Camera.h"
#include "Player.h"

void TeleportStair::onInitFromFile(ifstream & fs, int mapHeight)
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

	playerY = mapHeight - playerY;
	cameraY = mapHeight - cameraY;
}

void TeleportStair::setParam(const char * name, int value)
{
	if (strcmp(name, "playerX") == 0) this->playerX = value;
	if (strcmp(name, "playerY") == 0) this->playerY = value;
	if (strcmp(name, "cameraX") == 0) this->cameraX = value;
	if (strcmp(name, "cameraY") == 0) this->cameraY = value;
	if (strcmp(name, "contactDirection") == 0) this->contactDirection = value;
}

void TeleportStair::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{	
	if (other == PLAYER && ny == contactDirection && PLAYER->getVy() == 0)
	{
		PLAYER->setX(playerX);
		PLAYER->setY(playerY);
		CAMERA->setX(cameraX);
		CAMERA->setY(cameraY);
	}
}

TeleportStair::TeleportStair()
{
}


TeleportStair::~TeleportStair()
{
}
