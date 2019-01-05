#include "Player.h"
#include "debug.h"
#include "Game.h"
#include"Camera.h"
#include <string>
#include "SubWeaponHolyWater.h"
#include "SubWeaponKnife.h"
#include "SubWeaponTheAx.h"
#include "ScoreBar.h"

Player::Player()
{
	
	setWidth(PLAYER_WIDTH);
	setHeight(PLAYER_NORMAL_HEIGHT);
	setPhysicsEnable(true);
	setPlayerState(PLAYER_STATE_NORMAL);
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_SIMON));
	setSubWeapon(PLAYER_NO_SUBWEAPON);
	eatEffectDelay.init(1000);
	flashEffectDelay.init(600);
	flashEffectTime.init(20);
	deadActionTime.init(2000);
}

Player * Player::instance = 0;

Player * Player::getInstance()
{
	if (instance == 0) {
		instance = new Player();
	}
	return instance;
}

PLAYER_STATE Player::getPlayerState()
{
	return this->playerState;
}

void Player::setPlayerState(PLAYER_STATE playerState)
{
	this->playerState = playerState;
}

void Player::setAction(int action)
{
	BaseObject::setAction(getDir()*PLAYER_ACTION_COUNT + action);
}

PLAYER_STAIR_STATE Player::getPlayerStairState()
{
	return this->playerStairState;
}

void Player::setPlayerStairState(PLAYER_STAIR_STATE playerStairState)
{
	this->playerStairState = playerStairState;
}

void Player::setStartStair()
{
	setPhysicsEnable(false);
	playerStairDestX = getX();
	playerStairDestY = getY();
	setPlayerState(PLAYER_STATE_ON_STAIR);
	setPlayerStairState(PLAYER_STAIR_STATE_READY);
}

void Player::setStopStair()
{
	setVx(0);
	setVy(0);
	setPauseAnimation(false);
	setPhysicsEnable(true);
	setPlayerState(PLAYER_STATE_NORMAL);
}

void Player::goStairUp()
{
	playerStairDestY = getY() + 8;
	if (stairDirection == 1)
	{
		// stair phải
		playerStairDestX += 8;
		setDir(RIGHT);
	}
	else
	{
		// stair trái
		playerStairDestX -= 8;
		setDir(LEFT);
	}
	setPlayerStairState(PLAYER_STAIR_STATE_GO_UP);
	setPauseAnimation(false);
	setAction(PLAYER_ACTION_GO_STAIR_UP);
}

void Player::goStairDown()
{
	playerStairDestX -= 8;
	if (stairDirection == 1)
	{
		// stair phải
		playerStairDestX -= 8;
		setDir(LEFT);
	}
	else
	{
		// stair trái
		playerStairDestX += 8;
		setDir(RIGHT);
	}

	setPlayerStairState(PLAYER_STAIR_STATE_GO_DOWN);
	setPauseAnimation(false);
	setAction(PLAYER_ACTION_GO_STAIR_DOWN);
}

int Player::getPlayerStairDestX()
{
	return this->playerStairDestX;
}

int Player::getPlayerStairDestY()
{
	return this->playerStairDestY;
}

void Player::setStairDirection(int stairDirection)
{
	this->stairDirection = stairDirection;
}

void Player::updatePlayerEvent()
{
	//DebugOut((wchar_t*)L"Update getAction %d \n", getAction());

	switch (PLAYER->getPlayerState())
	{
	case PLAYER_STATE_SEAT:
		PLAYER->setVx(0);
		break;
	case PLAYER_STATE_NORMAL:
		PLAYER->handleUndyingStatePlayer();
		break;
	case PLAYER_STATE_ON_STAIR:
		PLAYER->handleUndyingStatePlayer();
		switch (PLAYER->getPlayerStairState())
		{
		case PLAYER_STAIR_STATE_READY:
			return;
		case PLAYER_STAIR_STATE_GO_UP:
			if (PLAYER->getDir() == RIGHT)
				PLAYER->setDx(PLAYER_STAIR_DX);
			else
				PLAYER->setDx(-PLAYER_STAIR_DX);
			PLAYER->setDy(PLAYER_STAIR_DY);
			break;
		case PLAYER_STAIR_STATE_GO_DOWN:
			if (PLAYER->getDir() == RIGHT)
				PLAYER->setDx(PLAYER_STAIR_DX);
			else
				PLAYER->setDx(-PLAYER_STAIR_DX);
			PLAYER->setDy(-PLAYER_STAIR_DY);
			break;
		default:
			break;
		}

		if (PLAYER->getPlayerStairState() == PLAYER_STAIR_STATE_GO_UP || PLAYER->getPlayerStairState() == PLAYER_STAIR_STATE_GO_DOWN)
		{
			if (PLAYER->getDir() == RIGHT)
			{
				if (PLAYER->getX() + PLAYER->getDx() > PLAYER->getPlayerStairDestX())
				{
					PLAYER->setStartStair();
					PLAYER->setX(PLAYER->getPlayerStairDestX());
					PLAYER->setY(PLAYER->getPlayerStairDestY());
				}
			}
			else
			{
				if (PLAYER->getX() + PLAYER->getDx() < PLAYER->getPlayerStairDestX())
				{
					PLAYER->setStartStair();
					PLAYER->setX(PLAYER->getPlayerStairDestX());
					PLAYER->setY(PLAYER->getPlayerStairDestY());
				}
			}
		}
		break;
	case PLAYER_STATE_DIE:
		if (PLAYER->isGrounded()) {
			PLAYER->setVx(0);
			PLAYER->setVy(0);
			PLAYER->setDx(0);
			PLAYER->setDy(0);
			PLAYER->setIsUndying(true);
			PLAYER->flashEffectDelay.start(600);
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
		}
		break;
	case PLAYER_STATE_ATTACK:
		if (PLAYER->getIsLastFrameAnimationDone())
		{
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
			PLAYER->setY(PLAYER->getY() + (PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT));
			PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
		}
		break;
	case PLAYER_STATE_ATTACK_SUBWEAPON:
		if (PLAYER->getIsLastFrameAnimationDone())
		{
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
			PLAYER->setY(PLAYER->getY() + (PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT));
			PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
		}
		break;
	case PLAYER_STATE_EAT_EFFECT:
		PLAYER->eatEffectDelay.update();
		if (PLAYER->eatEffectDelay.isTerminated())
		{
			PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
			return;
		}
		PLAYER->setAction(PLAYER_ACTION_EAT_EFFECT);
		PLAYER->setVx(0);
		PLAYER->setVy(0);
		break;
	case PLAYER_STATE_DEAD:
		PLAYER->setVx(0);
		PLAYER->setDx(0);
		PLAYER->deadActionTime.update();
		if (PLAYER->deadActionTime.isTerminated()) {
			if (SCOREBAR->getPlayerLife() <= 0) {

			}
			else {
				PLAYER->setIsUndying(false);
				SCOREBAR->restoreHealth();
				WORLD_CHILD_MANAGER->resetLocationInWorldChild();
				PLAYER->setAction(PLAYER_ACTION_STAND);
				PLAYER->setPlayerState(PLAYER_STATE_NORMAL);
				PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
				PLAYER->setIsAllowUpdateRender(true, true);
			}
		}
		break;
	default:
		break;
	}
}

void Player::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (playerState != PLAYER_STATE_ON_STAIR)
	{
		BaseObject::onCollision(other, collisionTime, nx, ny);
	}
}


void Player::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	BaseObject::setIsLastFrameAnimationDone(isLastFrameAnimationDone);
	if (isLastFrameAnimationDone)
		if (playerState == PLAYER_STATE_ATTACK)
			this->setFrame(this->getGraphicsAssets()->getAction(this->getAction())->getFrameCount() - 1);
}

bool Player::getIsUndying()
{
	return this->isUndying;
}

void Player::setIsUndying(bool isUndying)
{
	this->isUndying = isUndying;
}

void Player::handleUndyingStatePlayer()
{
	if (getIsUndying()) {
		flashEffectDelay.update();

		if (flashEffectTime.atTime()) {
			if (getIsAllowRender()) {
				setIsAllowUpdateRender(true, false);
				goto checkstop;
			}
			if (!getIsAllowRender()) {
				setIsAllowUpdateRender(true, true);
			}
		}

	checkstop:
		if (flashEffectDelay.isTerminated()) {
			setIsUndying(false);
			setIsAllowUpdateRender(true, true);
		}
	}
}

void Player::setSubWeapon(PLAYER_SUBWEAPON playerSubWeapon)
{
	this->playerSubWeapon = playerSubWeapon;
}

PLAYER_SUBWEAPON Player::getSubWeapon()
{
	return this->playerSubWeapon;
}

void Player::handleAttackSubWeapon()
{
	switch (getSubWeapon())
	{
		case PLAYER_SUBWEAPON_KNIFE:
		{
			SubWeaponKnife* knife = new SubWeaponKnife();
			break;
		}
		case PLAYER_SUBWEAPON_THE_AX:
		{
			SubWeaponTheAx* theAx = new SubWeaponTheAx();
			break;
		}
		case PLAYER_SUBWEAPON_HOLYWATER:
		{
			SubWeaponHolyWater* holyWater = new SubWeaponHolyWater();
			break;
		}
	}
}

bool Player::getIsHaveHolyCross()
{
	return this->isHaveHolyCross;
}

void Player::setIsHaveHolyCross(bool isHaveHolyCross)
{
	this->isHaveHolyCross = isHaveHolyCross;
}


Player::~Player()
{

}
