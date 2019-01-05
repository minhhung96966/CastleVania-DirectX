#include "BreakWall2.h"
#include "GraphicsAssetsManager.h"


BreakWall2::BreakWall2()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_BREAKWALL2));
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(false);
}


BreakWall2::~BreakWall2()
{
}
