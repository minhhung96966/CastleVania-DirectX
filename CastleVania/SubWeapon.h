#pragma once
#include "BaseObject.h"
class SubWeapon :
	public BaseObject
{
	bool isRender;
public:
	bool isRemove;
	void setAction(int action) override;
	void onIntersection(BaseObject* other) override;
	void render(Camera* camera);
	void onCollision(BaseObject* other, float collisionTime, int nx, int ny) override;
	void setIsRender(bool isRender);
	bool getIsRender();
	SubWeapon();
	~SubWeapon();
};

