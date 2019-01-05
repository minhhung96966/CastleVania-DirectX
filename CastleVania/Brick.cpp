#include "Brick.h"
#include "GraphicsAssetsManager.h"
#include "ExplosionEffect.h"
#include "MorningStar.h"


Brick::Brick()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_BRICK));
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(false);
	setIsStopCollision(false);
}

void Brick::onIntersection(BaseObject * other)
{
	if (other == MORNING_STAR && !getIsPreviousTriggerMorningStar()) {
		setIsAllowUpdateRender(false, false);
		setIsPreviousTriggerMorningStar(true);
		setIsStopCollision(true);

		EXPLOSION_EFFECT->setX(this->getX());
		EXPLOSION_EFFECT->setY(this->getY());
		EXPLOSION_EFFECT->effectDelay.start();
		EXPLOSION_EFFECT->setIsAllowUpdateRender(true, true);
	}
	
}

void Brick::onReborn()
{
	//Nếu đã chết rồi thì không reborn
	if (getIsPreviousTriggerMorningStar()) {
		setIsStopCollision(true);
		return;
	}
	BaseObject::onReborn();
	setIsPreviousTriggerMorningStar(false);
	setIsStopCollision(false);
}


Brick::~Brick()
{
}
