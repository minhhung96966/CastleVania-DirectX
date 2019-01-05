#include "ItemTheAx.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"
#include "Player.h"


ItemTheAx::ItemTheAx()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_THEAX));
	setIsAllowUpdateRender(false, false);
}

void ItemTheAx::onContactPlayer()
{
	Item::onContactPlayer();
	PLAYER->setSubWeapon(PLAYER_SUBWEAPON_THE_AX);
	SCOREBAR->setSubWeapon(this);
}


ItemTheAx::~ItemTheAx()
{
}
