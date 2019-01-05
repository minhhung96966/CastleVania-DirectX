#include "Enemy.h"
#include "MorningStar.h"
#include "ExplosionEffect.h"
#include "Player.h"
#include "ListGateInstance.h"
#include "ScoreBar.h"
#include "SubWeapon.h"

void Enemy::setIsPreviousTriggerMorningStar(bool isPreviousTriggerMorningStar)
{
	this->isPreviousTriggerMorningStar = isPreviousTriggerMorningStar;
}

bool Enemy::getIsPreviousTriggerMorningStar()
{
	return this->isPreviousTriggerMorningStar;
}

void Enemy::setDirectionToPlayer()
{
	if (PLAYER->getMidX() < getMidX())
		setDir(LEFT);
	else
		setDir(RIGHT);
}

void Enemy::onHitByWeapon()
{
	setIsAllowUpdateRender(false, false);
	setIsPreviousTriggerMorningStar(true);
}

void Enemy::onIntersection(BaseObject * other)
{
	//https://stackoverflow.com/questions/500493/c-equivalent-of-instanceof

	if (
		(other == MORNING_STAR && !getIsPreviousTriggerMorningStar()) || 
		(dynamic_cast<SubWeapon*>(other) != nullptr && !getIsPreviousTriggerMorningStar())
		) 
	{
		onHitByWeapon();

		SCOREBAR->increaseScore(100);

		EXPLOSION_EFFECT->setX(this->getX());
		EXPLOSION_EFFECT->setY(this->getY());
		EXPLOSION_EFFECT->effectDelay.start();
		EXPLOSION_EFFECT->setIsAllowUpdateRender(true, true);

	}
	else if (other == PLAYER &&
		getIsAllowUpdate() && 
		getIsAllowRender() && 
		!(PLAYER->getPlayerState() == PLAYER_STATE_DIE) &&
		!PLAYER->getIsUndying())
	{
		SCOREBAR->increaseHealth(-2);

		if (SCOREBAR->getHealth() <= 0)
		{
			SCOREBAR->setPlayerLife(SCOREBAR->getPlayerLife() - 1);
			PLAYER->deadActionTime.start();
			PLAYER->setIsUndying(true);
			PLAYER->setHeight(PLAYER_DEAD_HEIGHT);
			PLAYER->setY(PLAYER->getY() - PLAYER_NORMAL_HEIGHT + PLAYER_DEAD_HEIGHT);
			PLAYER->setAction(PLAYER_ACTION_DEAD);
			PLAYER->setPlayerState(PLAYER_STATE_DEAD);
			return;
		}

		//Khi player đang ở cầu thang mà chết thì chỉ chớp nháy
		if (PLAYER->getPlayerState() == PLAYER_STATE_ON_STAIR) {
			PLAYER->setIsUndying(true);
			PLAYER->flashEffectDelay.start(600);
		}
		else {
			if (PLAYER->getPlayerState() == PLAYER_STATE_SEAT || PLAYER->getAction() == PLAYER_ACTION_SEAT_ATTACK) {
				PLAYER->setHeight(PLAYER_NORMAL_HEIGHT);
				PLAYER->setY(PLAYER->getY() + PLAYER_NORMAL_HEIGHT - PLAYER_SEAT_HEIGHT);
			}


			PLAYER->setAction(PLAYER_ACTION_DIE);
			PLAYER->setPlayerState(PLAYER_STATE_DIE);
			if (PLAYER->getDir() == 0)
				PLAYER->setVx(-PLAYER_VX_DIE);
			else 
				PLAYER->setVx(PLAYER_VX_DIE);
			PLAYER->setVy(PLAYER_VY_DIE);
		}
	}
}

void Enemy::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	//Chỉ xét va chạm theo phương thẳng với sàn
	if (ny == 1)
	{
		BaseObject::onCollision(other, collisionTime, nx, ny);
	}
}

void Enemy::render(Camera * camera)
{
	if (PLAYER->getIsHaveHolyCross()) return;
	BaseObject::render(camera);
}

void Enemy::onUpdate(float dt)
{
	if (PLAYER->getIsHaveHolyCross()) return;
	BaseObject::onUpdate(dt);
}

void Enemy::onReborn()
{
	if (PLAYER->getIsHaveHolyCross()) return;

	//Nếu đang chuyển cảnh
	for (size_t i = 0; i < ListGateInstance::getGateList()->size(); i++)
	{
		if (ListGateInstance::getGateList()->at(i)->getOnChangeWorldChildGate()) {
			return;
		}
	}

	BaseObject::onReborn();
	setIsPreviousTriggerMorningStar(false);
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}
