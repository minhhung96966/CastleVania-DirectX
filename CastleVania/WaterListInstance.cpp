#include "WaterListInstance.h"
#include "Collision.h"
#include "Camera.h"

vector<BaseObject*>* WaterListInstance::waterList = 0;

WaterListInstance::WaterListInstance()
{
}

vector<BaseObject*>* WaterListInstance::getWaterList()
{
	if (waterList == 0) {
		waterList = new vector<BaseObject*>();
	}
	return waterList;
}

void WaterListInstance::deleteObjectInList()
{
	for (int i = 0; i < waterList->size(); i++) {
		if (!Collision::AABBCheck(waterList->at(i), CAMERA)) {
			auto water = waterList->at(i);
			waterList->erase(waterList->begin() + i);
			delete water;
			i--;
		}
	}
}


WaterListInstance::~WaterListInstance()
{
}
