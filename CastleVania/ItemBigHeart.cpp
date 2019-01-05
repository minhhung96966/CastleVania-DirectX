#include "ItemBigHeart.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"


void ItemBigHeart::onContactPlayer()
{
	Item::onContactPlayer();
	SCOREBAR->increaseHeartCount(5);
}

ItemBigHeart::ItemBigHeart()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_BIG_HEART));
	setIsAllowUpdateRender(false, false);
}


ItemBigHeart::~ItemBigHeart()
{
}
