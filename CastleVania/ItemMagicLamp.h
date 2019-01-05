#pragma once
#include "Item.h"
class ItemMagicLamp :
	public Item
{
public:
	void onContactPlayer() override;
	ItemMagicLamp();
	~ItemMagicLamp();
};

