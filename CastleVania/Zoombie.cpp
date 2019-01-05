#include "Zoombie.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"

Zoombie::Zoombie()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ZOOMBIE));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
	setDir(LEFT);
	setAction(0);
}


void Zoombie::onUpdate(float dt)
{
	if (getIsAllowUpdate() && getIsAllowRender() && (this->getMidX() - PLAYER->getMidX() <= ZOOMBIE_DETECT_PLAYER_DISTANCE)) {
		if(getDir() == LEFT) 
			setVx(-ZOOMBIE_VX);
		else 
			setVx(ZOOMBIE_VX);
	}
	BaseObject::onUpdate(dt);
}

void Zoombie::setToInitLocation()
{
	BaseObject::setToInitLocation();
	setDirectionToPlayer();
	setAction(0);
}

void Zoombie::setAction(int action)
{
	BaseObject::setAction(getDir() + action);
}





Zoombie::~Zoombie()
{
	
}
