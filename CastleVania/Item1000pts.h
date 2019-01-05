#pragma once
#include "Item.h"
class Item1000pts :
	public Item
{
public:
	void onContactPlayer() override;
	Item1000pts();
	~Item1000pts();
};

