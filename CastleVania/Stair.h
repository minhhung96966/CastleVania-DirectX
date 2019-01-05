#pragma once
#include "BaseObject.h"
class Stair :
	public BaseObject
{
	bool isRightUp, isTop;
public:
	void onInitFromFile(ifstream& fs, int mapHeight) override;
	void setParam(const char* name, bool value);
	void onIntersection(BaseObject* other) override;
	int getVerticalMoving();
	int getHorizontalMoving();
	Stair();
	~Stair();
};

