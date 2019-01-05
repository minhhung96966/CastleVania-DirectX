#pragma once
#include "Item.h"
class ItemIncreaseHealth :
	public Item
{
public:
	void onContactPlayer() override;
	ItemIncreaseHealth();
	~ItemIncreaseHealth();
};

