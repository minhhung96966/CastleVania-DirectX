#include "ItemEndGame.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"
ItemEndGame* ItemEndGame::instance = NULL;
ItemEndGame * ItemEndGame::getInstance()
{
	if (instance == NULL) {
		instance = new ItemEndGame();
	}
	return instance;
}

void ItemEndGame::onIntersection(BaseObject * other)
{
	if (other == PLAYER && getIsAllowUpdate() && getIsAllowRender()) {
		Item::onContactPlayer();
	}
}

void ItemEndGame::onUpdate(float dt)
{
	delayWaitTime.update();
	if (delayWaitTime.isTerminated()) {
		this->setIsAllowUpdateRender(true, true);
		int frameWidth = getGraphicsAssets()->getWidth(getAction(), getFrame());
		int frameHeight = getGraphicsAssets()->getHeight(getAction(), getFrame());
		setWidth(frameWidth);
		setHeight(frameHeight);
		this->setPhysicsEnable(true);
	}
	Item::onUpdate(dt);
}

ItemEndGame::ItemEndGame()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_ITEM_ENDGAME));
	setIsAllowUpdateRender(true, false);
	delayWaitTime.init(2000);
	instance = this;
}


ItemEndGame::~ItemEndGame()
{
}
