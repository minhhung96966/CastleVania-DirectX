#include "Candle.h"
#include "GraphicsAssetsManager.h"



Candle::Candle()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_CANDLE));
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(false);
}


Candle::~Candle()
{
}
