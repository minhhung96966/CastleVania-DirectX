#pragma once
#include "Item.h"
#include "Player.h"
class ItemHolycross :
	public Item
{
	
public:
	void onContactPlayer() override;
	ItemHolycross();
	~ItemHolycross();
};

