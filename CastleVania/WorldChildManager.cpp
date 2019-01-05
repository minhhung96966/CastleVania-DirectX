#include "WorldChildManager.h"
#include "Camera.h"
#include "Player.h"
#include "Grid.h"


WorldChildManager* WorldChildManager::__instance = NULL;

WorldChildManager::WorldChildManager()
{

}

WorldChildManager* WorldChildManager::getInstance()
{
	if (__instance == NULL) __instance = new WorldChildManager();
	return __instance;
}


void WorldChildManager::readInformationWorldChild(const char* worldChildsPath)
{
	//Read childWorld infomation
	int numberOfWorldChilds = 0;
	ifstream fsWorldChild(worldChildsPath);
	ignoreLineIfstream(fsWorldChild, 1);
	fsWorldChild >> numberOfWorldChilds;
	for (size_t i = 0; i < numberOfWorldChilds; i++)
	{
		ignoreLineIfstream(fsWorldChild, 4);
		WorldChild* worldChild = new WorldChild();
		fsWorldChild >> worldChild->x >> worldChild->y >> worldChild->width >> worldChild->height;

		ignoreLineIfstream(fsWorldChild, 2);
		fsWorldChild >> worldChild->CameraX >> worldChild->CameraY;

		ignoreLineIfstream(fsWorldChild, 2);
		fsWorldChild >> worldChild->PlayerX >> worldChild->PlayerY;

		worldChilds.push_back(worldChild);
	}
}

void WorldChildManager::setCurrentWorldChild(int worldChildIndex)
{
	this->currentWorldChild = worldChilds[worldChildIndex];
}

WorldChild * WorldChildManager::getCurrentWorldChild()
{
	return currentWorldChild;
}

void WorldChildManager::resetLocationInWorldChild()
{
	PLAYER->setX(getCurrentWorldChild()->PlayerX);
	PLAYER->setY(getCurrentWorldChild()->PlayerY);

	PLAYER->setDx(0);
	PLAYER->setDy(0);
	PLAYER->setVx(0);
	PLAYER->setVy(0);

	CAMERA->setX(getCurrentWorldChild()->CameraX);
	CAMERA->setY(getCurrentWorldChild()->CameraY);

	//DebugOut((wchar_t*)L"%f \n", getCurrentWorldChild()->PlayerX);
	//DebugOut((wchar_t*)L"%f \n", getCurrentWorldChild()->PlayerY);

	//DebugOut((wchar_t*)L"%f \n", Player::getInstance()->getX());
	//DebugOut((wchar_t*)L"%f \n", Player::getInstance()->getY());

}

WorldChildManager::~WorldChildManager()
{

}