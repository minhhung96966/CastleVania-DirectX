#include "ItemMorningStar.h"
#include "Player.h"
#include "MorningStar.h"



void ItemMorningStar::onContactPlayer()
{
	PLAYER->setPlayerState(PLAYER_STATE::PLAYER_STATE_EAT_EFFECT);
	PLAYER->eatEffectDelay.start();
	MORNING_STAR->growUpMorningStar();
	Item::onContactPlayer();
}

ItemMorningStar::ItemMorningStar()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_MORNING_STAR));
	setIsAllowUpdateRender(false, false);
}


ItemMorningStar::~ItemMorningStar()
{
}
