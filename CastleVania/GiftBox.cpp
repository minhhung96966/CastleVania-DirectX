#include "GiftBox.h"
#include "MorningStar.h"
#include "ExplosionEffect.h"
#include "SubWeapon.h"

GiftBox::GiftBox()
{
}

void GiftBox::setIsPreviousTriggerMorningStar(bool isPreviousTriggerMorningStar)
{
	this->isPreviousTriggerMorningStar = isPreviousTriggerMorningStar;
}

bool GiftBox::getIsPreviousTriggerMorningStar()
{
	return this->isPreviousTriggerMorningStar;
}

void GiftBox::onIntersection(BaseObject * other)
{
	if (
		(other == MORNING_STAR && !getIsPreviousTriggerMorningStar())	||
		(dynamic_cast<SubWeapon*>(other) != nullptr && !getIsPreviousTriggerMorningStar())
		) 
	{
		setIsAllowUpdateRender(false, false);
		setIsPreviousTriggerMorningStar(true);

		EXPLOSION_EFFECT->setX(this->getX());
		EXPLOSION_EFFECT->setY(this->getY());
		EXPLOSION_EFFECT->effectDelay.start();
		EXPLOSION_EFFECT->setIsAllowUpdateRender(true, true);
	}
}

void GiftBox::onReborn()
{
	if (getIsPreviousTriggerMorningStar()) return; //Nếu đã chết rồi thì không reborn
	BaseObject::onReborn();
	setIsPreviousTriggerMorningStar(false);
}

GiftBox::~GiftBox()
{
}
