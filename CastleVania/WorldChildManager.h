#pragma once
#include <vector>

using namespace std;


struct WorldChild
{
	int x, y, width, height, CameraX, CameraY, PlayerX, PlayerY;
};


class WorldChildManager
{
	static WorldChildManager* __instance;

	vector<WorldChild*> worldChilds;
	WorldChild* currentWorldChild;
public:

	static WorldChildManager* getInstance();

	void readInformationWorldChild(const char* worldChildsPath);

	void setCurrentWorldChild(int worldChildIndex);
	WorldChild* getCurrentWorldChild();

	void resetLocationInWorldChild();

	WorldChildManager();
	~WorldChildManager();
};

