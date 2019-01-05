#include "Tilemap.h"
#include "GraphicsAssetsManager.h"
#include "BaseObject.h"
#include "Zoombie.h"
#include "Collision.h"
#include "Camera.h"
#include "ObjectTagGroupManager.h"
#include "WorldChildManager.h"
#include "Grid.h"
#include "DelayTime.h"

class Level
{
	Tilemap tilemap;
	ObjectTagGroupManager* objectTagGroupManager;
	WorldChildManager* worldChildManager;
	Grid* grid;
	static Level* instance;
public:
	DelayTime effectHollyCrossDelay;
	GameTime effectHollyCrossTime;
	bool flatRenderTileMap;

	static Level* getInstance();
	void Init(const char* folderPath);
	void InitAllObjectsInLevel(const char* objectPathString);
	void handleRenderTileMap();
	void update(float dt);
	void render();

	Level();
	~Level();
};



