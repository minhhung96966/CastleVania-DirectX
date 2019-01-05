#include "ObjectTagGroupManager.h"
#include "Collision.h"
#include "BaseObject.h"


ObjectTagGroupManager* ObjectTagGroupManager::__instance = NULL;

ObjectTagGroupManager * ObjectTagGroupManager::getInstance()
{
	if (__instance == NULL) __instance = new ObjectTagGroupManager();
	return __instance;
}

ObjectTagGroupManager::ObjectTagGroupManager()
{
	//khoi tao phan loai doi tuong
	for (int i = 0; i < OBJECT_TAG_COUNT; i++) {
		objectCategories.push_back(new vector<BaseObject*>());
	}
}

void ObjectTagGroupManager::readInformationFromFile(const char * objectTagGroupPath)
{
	int numberOfObjectTagGroups = 0;
	ifstream fsColli(objectTagGroupPath);
	fsColli >> numberOfObjectTagGroups;
	for (int i = 0; i < numberOfObjectTagGroups; i++) {
		int objectTag1, objectTag2;
		fsColli >> objectTag1 >> objectTag2;
		ObjectTagGroup* objectTagGroup = new ObjectTagGroup();
		objectTagGroup->OBJECT_TAG_1 = (OBJECT_TAG)objectTag1;
		objectTagGroup->OBJECT_TAG_2 = (OBJECT_TAG)objectTag2;
		objectTagGroups.push_back(objectTagGroup);
	}
}

void ObjectTagGroupManager::addObjectToEachCategories(BaseObject * obj)
{
	objectCategories[obj->getObjectTag()]->push_back(obj);
}

void ObjectTagGroupManager::onCollision()
{
	//Xet va cham cho cac loai doi tuong voi nhau
	for (auto objectTagGroup : objectTagGroups) {

		OBJECT_TAG ot1 = objectTagGroup->OBJECT_TAG_1;
		OBJECT_TAG ot2 = objectTagGroup->OBJECT_TAG_2;

		//Danh sach doi tuong thuoc object_tag 1
		vector<BaseObject*> collection1 = *objectCategories[ot1];
		//Danh sach doi tuong thuoc object_tag 2
		vector<BaseObject*> collection2 = *objectCategories[ot2];

		for (auto c1 : collection1) {
			for (auto c2 : collection2) {
				Collision::CheckCollision(c1, c2);
			}
		}
	}
}


ObjectTagGroupManager::~ObjectTagGroupManager()
{
}
