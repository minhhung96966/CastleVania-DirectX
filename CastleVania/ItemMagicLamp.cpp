#include "ItemMagicLamp.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"



ItemMagicLamp::ItemMagicLamp()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_MAGIC_LAMP));
	setIsAllowUpdateRender(false, false);
}

void ItemMagicLamp::onContactPlayer()
{
	Item::onContactPlayer();
	PLAYER->setIsUndying(true);
	PLAYER->flashEffectDelay.start(5000);
}

ItemMagicLamp::~ItemMagicLamp()
{
}
