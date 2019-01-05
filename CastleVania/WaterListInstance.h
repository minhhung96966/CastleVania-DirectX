#pragma once
#include "BaseObject.h"

class WaterListInstance
{
	static vector<BaseObject*>* waterList;
public:
	static vector<BaseObject*>* getWaterList();
	static void deleteObjectInList();
	WaterListInstance();
	~WaterListInstance();
};

