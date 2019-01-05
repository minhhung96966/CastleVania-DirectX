#include "Item700pts.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"

void Item700pts::onContactPlayer()
{
	Item::onContactPlayer();
	SCOREBAR->increaseScore(700);
}

Item700pts::Item700pts()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_700PTS));
	setIsAllowUpdateRender(false, false);
}


Item700pts::~Item700pts()
{
}
