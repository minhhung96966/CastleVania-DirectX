#include "Item.h"
#include "MorningStar.h"
#include "Player.h"
#include "SubWeapon.h"

void Item::setIsPreviousTriggerMorningStar(bool isPreviousTriggerMorningStar)
{
	this->isPreviousTriggerMorningStar = isPreviousTriggerMorningStar;
}

bool Item::getIsPreviousTriggerMorningStar()
{
	return isPreviousTriggerMorningStar;
}

void Item::onIntersection(BaseObject * other)
{
	if (
		(other == MORNING_STAR && !getIsPreviousTriggerMorningStar()) ||
		(dynamic_cast<SubWeapon*>(other) != nullptr && !getIsPreviousTriggerMorningStar())
		) 
	{
		int frameWidth = getGraphicsAssets()->getWidth(getAction(), getFrame());
		int frameHeight = getGraphicsAssets()->getHeight(getAction(), getFrame());
		setWidth(frameWidth);
		setHeight(frameHeight);
		isPreviousTriggerMorningStar = true;
		this->setIsAllowUpdateRender(true, true);
		this->setPhysicsEnable(true);
	}
	else if (other == PLAYER && getIsAllowUpdate() && getIsAllowRender()) {
		onContactPlayer();
	}
}

void Item::onContactPlayer()
{
	this->setIsAllowUpdateRender(false, false);
}

void Item::onReborn()
{
	if (getIsPreviousTriggerMorningStar()) return; //Nếu đã chết rồi thì không reborn
	setToInitLocation();
	setIsPreviousTriggerMorningStar(false);
}

Item::Item()
{
	setIsPreviousTriggerMorningStar(false);
}


Item::~Item()
{
}
