#pragma once
#include "GiftBox.h"
class Brick :
	public GiftBox
{
public:
	void onIntersection(BaseObject* other) override;
	void onReborn() override;
	Brick();
	~Brick();
};

