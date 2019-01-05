#include "Water.h"
#include "GraphicsAssetsManager.h"
#include "WaterListInstance.h"


Water::Water()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_WATER));
	WaterListInstance::getWaterList()->push_back(this);
}


Water::~Water()
{
}
