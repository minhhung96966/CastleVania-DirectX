#pragma once
#include "Enemy.h"


class Zoombie :
	public Enemy
{
public:
	void onUpdate(float dt) override;
	void setToInitLocation() override;
	void setAction(int action) override;
	Zoombie();
	~Zoombie();
};

