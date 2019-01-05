#include "SubWeapon.h"
#include "ListSubWeaponInstance.h"
#include "Player.h"
#include "Enemy.h"
#include "GiftBox.h"

SubWeapon::SubWeapon()
{
	setIsAllowUpdateRender(true, false);
	setDir(PLAYER->getDir());
	ListSubWeaponInstance::getListSupWeapon()->push_back(this);
	if (getDir() == RIGHT) {
		this->setX(PLAYER->getX() + 22);
		this->setY(PLAYER->getY() - 10);
		this->setFrame(0);
	}
	else {
		this->setX(PLAYER->getX() - 22 - getWidth());
		this->setY(PLAYER->getY() - 10);
		this->setFrame(0);
	}
	setIsRender(false);
	isRemove = false;
}


void SubWeapon::setAction(int action)
{
	BaseObject::setAction(getDir() + action);
}

void SubWeapon::onIntersection(BaseObject * other)
{
	if (
		(dynamic_cast<Enemy*>(other) != nullptr && other->getIsAllowRender()) ||
		(dynamic_cast<GiftBox*>(other) != nullptr && other->getIsAllowRender())
		)
	{
		this->setIsAllowUpdateRender(false, false);
		isRemove = true;
		//this->setIsStopCollision(true);
	}
}

void SubWeapon::render(Camera * camera)
{
	if (getIsRender())
	{
		BaseObject::render(camera);
	}
}

void SubWeapon::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
}

void SubWeapon::setIsRender(bool isRender)
{
	this->isRender = isRender;
}

bool SubWeapon::getIsRender()
{
	return this->isRender;
}


SubWeapon::~SubWeapon()
{
}
