#include "Item400pts.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"

void Item400pts::onContactPlayer()
{
	Item::onContactPlayer();
	SCOREBAR->increaseScore(400);
}

Item400pts::Item400pts()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_400PTS));
	setIsAllowUpdateRender(false, false);
}


Item400pts::~Item400pts()
{
}
