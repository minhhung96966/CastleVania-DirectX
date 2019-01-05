#include "Item1000pts.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"



Item1000pts::Item1000pts()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_1000PTS));
	setIsAllowUpdateRender(false, false);
}

void Item1000pts::onContactPlayer()
{
	Item::onContactPlayer();
	SCOREBAR->increaseScore(100);
}

Item1000pts::~Item1000pts()
{
}
