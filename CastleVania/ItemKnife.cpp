#include "ItemKnife.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"
#include "Player.h"

ItemKnife::ItemKnife()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_KNIFE));
	setIsAllowUpdateRender(false, false);
}

void ItemKnife::onContactPlayer()
{
	Item::onContactPlayer();
	PLAYER->setSubWeapon(PLAYER_SUBWEAPON_KNIFE);
	SCOREBAR->setSubWeapon(this);
}

ItemKnife::~ItemKnife()
{
}
