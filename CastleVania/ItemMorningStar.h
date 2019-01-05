#pragma once
#include "Item.h"
class ItemMorningStar :
	public Item
{
public:
	void onContactPlayer() override;
	ItemMorningStar();
	~ItemMorningStar();
};

