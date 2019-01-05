#pragma once
#include "BaseObject.h"
#include "WorldChildManager.h"

class Gate1 :
	public BaseObject
{
public:
	void onIntersection(BaseObject* other) override;

	Gate1();
	~Gate1();
};

