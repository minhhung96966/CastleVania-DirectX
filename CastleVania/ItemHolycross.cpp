#include "ItemHolycross.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"
#include "Level.h"

void ItemHolycross::onContactPlayer()
{
	Item::onContactPlayer();
	PLAYER->setIsHaveHolyCross(true);
	LEVEL->effectHollyCrossDelay.start();
}

ItemHolycross::ItemHolycross()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_HOLYCROSS));
	setIsAllowUpdateRender(false, false);
}


ItemHolycross::~ItemHolycross()
{
}
