#include "Stair.h"
#include<string>
#include "Player.h"
#include "Game.h"


Stair::Stair()
{
}

void Stair::onInitFromFile(ifstream & fs, int mapHeight)
{
	BaseObject::onInitFromFile(fs, mapHeight);
	string name;
	bool value;
	//Ex: IsTop	0
	fs >> name >> value;
	setParam(name.c_str(), value);
	//Ex: IsRightStair	1
	fs >> name >> value;
	setParam(name.c_str(), value);
}

void Stair::setParam(const char * name, bool value)
{
	if (strcmp(name, "isTop") == 0) this->isTop = value;
	if (strcmp(name, "isRightUp") == 0) this->isRightUp = value;
}

int Stair::getVerticalMoving() //Lên - xuống
{
	if (isTop) return -1; //Xuống
	else return 1; //Lên
}

int Stair::getHorizontalMoving()  //Trái - phải
{
	if (isRightUp)
	{
		if (isTop) return -1; //Trái
		else return 1; //Phải
	}
	else
	{
		if (isTop) return 1; //Phải
		else return -1; //Trái
	}
}

//Xử lý giao nhau giữa 2 cục ở mỗi đầu cầu thang với player
void Stair::onIntersection(BaseObject * other)
{
	if (other == PLAYER) {
		if (GAME->IsKeyDown(DIK_UP)) {
			if (PLAYER->isGrounded() && PLAYER->getPlayerState() == PLAYER_STATE_NORMAL) {
				if (getVerticalMoving() == 1) {
					if (getHorizontalMoving() == 1) 
						PLAYER->setX(getX());
					else 
						PLAYER->setX(getRight());
					PLAYER->setStairDirection(getHorizontalMoving());
					PLAYER->setVx(0);
					PLAYER->setVy(0);
					PLAYER->setDx(0);
					PLAYER->setDy(0);
					PLAYER->setStartStair();
					PLAYER->setAction(PLAYER_ACTION_GO_STAIR_UP);
					PLAYER->setPauseAnimation(true);
				}
			}
		}
		if (GAME->IsKeyDown(DIK_DOWN)) {
			if ((PLAYER->isGrounded() && PLAYER->getPlayerState() == PLAYER_STATE_NORMAL) ||
				(PLAYER->isGrounded() && PLAYER->getPlayerState() == PLAYER_STATE_SEAT)) {
				if (getVerticalMoving() == -1) {
					PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
					if (getHorizontalMoving() == 1) 
						PLAYER->setX(getRight());
					else 
						PLAYER->setX(getX());
					PLAYER->setStairDirection((-1)*getHorizontalMoving());
					PLAYER->setVx(0);
					PLAYER->setVy(0);
					PLAYER->setDx(0);
					PLAYER->setDy(0);
					PLAYER->setStartStair();
					PLAYER->setAction(PLAYER_ACTION_GO_STAIR_DOWN);
					PLAYER->setPauseAnimation(true);
				}
			}
		}
		if (PLAYER->getPlayerState() == PLAYER_STATE_ON_STAIR)
		{
			//Đang đi lên đụng cục trên
			if (PLAYER->getDy() > 0 && this->isTop && PLAYER->getBottom() >= this->getBottom())
				PLAYER->setStopStair();
		
			//Đang đi xuống đụng cục dưới
			if (PLAYER->getDy() < 0 && !this->isTop)
				PLAYER->setStopStair();
		}
	}
}




Stair::~Stair()
{
}
