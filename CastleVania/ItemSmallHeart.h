#pragma once
#include "Item.h"
class ItemSmallHeart :
	public Item
{
public:
	void onContactPlayer() override;
	ItemSmallHeart();
	~ItemSmallHeart();
	
};

