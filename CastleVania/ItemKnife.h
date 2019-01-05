#pragma once
#include "Item.h"

class ItemKnife :
	public Item
{
public:
	void onContactPlayer() override;
	ItemKnife();
	~ItemKnife();
};

