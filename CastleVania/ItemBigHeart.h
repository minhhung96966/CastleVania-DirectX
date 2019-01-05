#pragma once
#include "Item.h"

class ItemBigHeart :
	public Item
{
public:
	void onContactPlayer() override;
	ItemBigHeart();
	~ItemBigHeart();
};

