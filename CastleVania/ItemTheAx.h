#pragma once
#include "Item.h"
class ItemTheAx :
	public Item
{
public:
	void onContactPlayer() override;
	ItemTheAx();
	~ItemTheAx();
};

