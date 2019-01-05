#include "MorningStar.h"
#include "GraphicsAssetsManager.h"
#include "Player.h"




MorningStar * MorningStar::instance = 0;

MorningStar::MorningStar()
{
	setCurrentType(MORNING_STAR_TYPE_1);
	setWidth(MORNING_STAR_TYPE_1_WIDTH);
	setHeight(MORNING_STAR_TYPE_1_HEIGHT);
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_MORNING_STAR));
}


MorningStar * MorningStar::getInstance()
{
	if (instance == 0)
	{
		instance = new MorningStar();
	}
	return instance;
}


void MorningStar::growUpMorningStar()
{
	if (getCurrentType() == MORNING_STAR_TYPE_1) {
		setCurrentType(MORNING_STAR_TYPE_2);
		setWidth(MORNING_STAR_TYPE_2_WIDTH);
		setHeight(MORNING_STAR_TYPE_2_HEIGHT);
	}
	else if (getCurrentType() == MORNING_STAR_TYPE_2) {
		setCurrentType(MORNING_STAR_TYPE_3);
		setWidth(MORNING_STAR_TYPE_3_WIDTH);
		setHeight(MORNING_STAR_TYPE_3_HEIGHT);
	}
}

MORNING_STAR_TYPE MorningStar::getCurrentType()
{
	return this->currentType;
}

void MorningStar::setCurrentType(MORNING_STAR_TYPE currentType)
{
	this->currentType = currentType;
	setAction(currentType);
}


void MorningStar::setAction(int action)
{
	BaseObject::setAction(getDir()*MORNING_STAR_TYPE_COUNT + action);
}

void MorningStar::onUpdate(float dt)
{
	if (PLAYER->getPlayerState() == PLAYER_STATE_ATTACK) {
			setDir(PLAYER->getDir());
			setAction(getCurrentType());
			if (getDir() == RIGHT) {
				if (PLAYER->getFrame() == 0) {
					this->setX(PLAYER->getX() - 6);
					this->setY(PLAYER->getY() - 8);
					this->setFrame(0);
				}
				else if (PLAYER->getFrame() == 1) {
					this->setX(PLAYER->getX() + 4);
					this->setY(PLAYER->getY() - 5);
					this->setFrame(1);
				}
				else if (PLAYER->getFrame() == 2) {
					this->setX(PLAYER->getX() + 22);
					this->setY(PLAYER->getY() - 8);
					this->setFrame(2);
					setIsStopCollision(false);
				}
			}
			else {
				if (PLAYER->getFrame() == 0) {
					this->setX(PLAYER->getX() + 6);
					this->setY(PLAYER->getY() - 8);
					this->setFrame(0);
				}
				else if (PLAYER->getFrame() == 1) {
					this->setX(PLAYER->getX() - 3);
					this->setY(PLAYER->getY() - 7);
					this->setFrame(1);
				}
				else if (PLAYER->getFrame() == 2) {
					this->setX(PLAYER->getX() - 22 - getWidth()); //-42 vì đổi anchor của roi ra phía đuôi, vì width của roi tính từ x, y sang phải
					this->setY(PLAYER->getY() - 8);
					this->setFrame(2);
					setIsStopCollision(false);
				}
			}
	}
	else {
		setIsStopCollision(true);
		return;
	}
}

void MorningStar::render(Camera * camera)
{
	if (PLAYER->getPlayerState() == PLAYER_STATE_ATTACK)
		BaseObject::render(camera);
	else
		return;
}

MorningStar::~MorningStar()
{

}
