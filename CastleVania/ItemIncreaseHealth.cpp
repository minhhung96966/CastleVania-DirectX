#include "ItemIncreaseHealth.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"


void ItemIncreaseHealth::onContactPlayer()
{
	Item::onContactPlayer();
	SCOREBAR->restoreHealth();
}

ItemIncreaseHealth::ItemIncreaseHealth()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_INCREASE_HEALTH));
	setIsAllowUpdateRender(false, false);
}


ItemIncreaseHealth::~ItemIncreaseHealth()
{
}
