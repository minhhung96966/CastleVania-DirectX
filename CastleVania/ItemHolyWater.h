#pragma once
#include "Item.h"
class ItemHolyWater :
	public Item
{

public:
	void onContactPlayer() override;
	ItemHolyWater();
	~ItemHolyWater();
};

