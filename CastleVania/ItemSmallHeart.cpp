#include "ItemSmallHeart.h"
#include "GraphicsAssetsManager.h"
#include"ScoreBar.h"

ItemSmallHeart::ItemSmallHeart()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_SMALL_HEART));
	setIsAllowUpdateRender(false, false);
}


ItemSmallHeart::~ItemSmallHeart()
{
}

void ItemSmallHeart::onContactPlayer()
{
	Item::onContactPlayer();
	SCOREBAR->increaseHeartCount(1);
}
