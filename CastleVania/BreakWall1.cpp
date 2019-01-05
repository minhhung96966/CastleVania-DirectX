#include "BreakWall1.h"
#include "GraphicsAssetsManager.h"



BreakWall1::BreakWall1()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_BREAKWALL1));
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(false);
}


BreakWall1::~BreakWall1()
{
}
