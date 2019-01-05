#pragma once
#include "BaseObject.h"
class TeleportStair :
	public BaseObject
{
	float playerX, playerY, cameraX, cameraY;
	int contactDirection; //1 (go down)   -1(go up)
public:
	void onInitFromFile(ifstream& fs, int mapHeight) override;
	void setParam(const char* name, int value);
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	TeleportStair();
	~TeleportStair();
};

