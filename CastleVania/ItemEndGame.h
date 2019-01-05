#pragma once
#include "Item.h"
#include "DelayTime.h"

class ItemEndGame :
	public Item
{
	static ItemEndGame* instance;
public:
	static ItemEndGame* getInstance();
	DelayTime delayWaitTime;
	void onIntersection(BaseObject* other) override;
	void onUpdate(float dt) override;
	ItemEndGame();
	~ItemEndGame();
};

