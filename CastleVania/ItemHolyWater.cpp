#include "ItemHolyWater.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"
#include "Player.h"



ItemHolyWater::ItemHolyWater()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_HOLYWATER));
	setIsAllowUpdateRender(false, false);
}

void ItemHolyWater::onContactPlayer()
{
	Item::onContactPlayer();
	PLAYER->setSubWeapon(PLAYER_SUBWEAPON_HOLYWATER);
	SCOREBAR->setSubWeapon(this);
}

ItemHolyWater::~ItemHolyWater()
{
}
