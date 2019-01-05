#pragma once
#include <vector>

using namespace std;


class BaseObject;

enum OBJECT_TAG {

	OBJECT_TAG_GROUND,
	OBJECT_TAG_ENEMY,
	OBJECT_TAG_OTHER,
	OBJECT_TAG_ACTIVEWATER,

	OBJECT_TAG_COUNT
};

struct ObjectTagGroup
{
	/* OBJECT_TAG của Move Object */
	OBJECT_TAG OBJECT_TAG_1;

	/* OBJECT_TAG của Static Object */
	OBJECT_TAG OBJECT_TAG_2;
};

class ObjectTagGroupManager
{
	vector<ObjectTagGroup*> objectTagGroups;
	vector<vector<BaseObject*>*> objectCategories;

	static ObjectTagGroupManager* __instance;
public:
	static ObjectTagGroupManager* getInstance();

	void readInformationFromFile(const char* objectTagGroupPath);

	void addObjectToEachCategories(BaseObject* obj);

	void onCollision();

	ObjectTagGroupManager();
	~ObjectTagGroupManager();
};

