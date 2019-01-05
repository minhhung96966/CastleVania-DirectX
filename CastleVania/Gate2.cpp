#include "Gate2.h"
#include "Player.h"
#include "Camera.h"
#include "WorldChildManager.h"
#include "Collision.h"
#include <string>
#include "ListGateInstance.h"
#include "GraphicsAssetsManager.h"
#include "ScoreBar.h"

Gate2::Gate2()
{
	setIsAllowUpdateRender(false, false);
	setOnChangeWorldChildGate(false);
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_GATE2));
	ListGateInstance::getGateList()->push_back(this);
}

void Gate2::onInitFromFile(ifstream & fs, int mapHeight)
{
	BaseObject::onInitFromFile(fs, mapHeight);
	string name;
	int value;
	fs >> name >> value;
	setParam(name.c_str(), value);
}

void Gate2::setParam(const char * name, int value)
{
	if (strcmp(name, "currentWorldChild") == 0) this->currentWorldChild = value;
}

void Gate2::setOnChangeWorldChildGate(boolean onChangeWorldChildGate)
{
	this->onChangeWorldChildGate = onChangeWorldChildGate;
}

boolean Gate2::getOnChangeWorldChildGate()
{
	return this->onChangeWorldChildGate;
}

void Gate2::changeWorldChildInGate(float dt, Grid * grid)
{
	switch (changeWorldChild2State)
	{
	case CHANGE_WORLDCHILD2_STATE_CAMERA_MOVE_TEMP:
		CAMERA->setDx(1);
		PLAYER->setVx(0);
		PLAYER->setDx(0);
		PLAYER->setAction(PLAYER_ACTION_STAND);
		if (CAMERA->getMidX() > getMidX())
		{
			setIsAllowUpdateRender(true, true);
			changeWorldChild2State = CHANGE_WORLDCHILD2_STATE_GATE_OPENING;
			setAction(GATE2_ACTION_OPENING);
		}
		break;
	case CHANGE_WORLDCHILD2_STATE_GATE_OPENING:
		CAMERA->setDx(0);
		if (getIsLastFrameAnimationDone())
		{
			setAction(GATE2_ACTION_OPENED);
			changeWorldChild2State = CHANGE_WORLDCHILD2_STATE_SIMON_MOVE;
		}
		break;
	case CHANGE_WORLDCHILD2_STATE_SIMON_MOVE:
		PLAYER->setDx(1);
		PLAYER->setAction(PLAYER_ACTION_RUN);
		if (PLAYER->getLeft() - getRight() > 35)
		{
			setAction(GATE2_ACTION_CLOSING);
			changeWorldChild2State = CHANGE_WORLDCHILD2_STATE_GATE_CLOSING;
		}
		break;
	case CHANGE_WORLDCHILD2_STATE_GATE_CLOSING:
		PLAYER->setDx(0);
		PLAYER->setVx(0);
		PLAYER->setAction(PLAYER_ACTION_STAND);
		if (getIsLastFrameAnimationDone())
		{
			setIsAllowUpdateRender(false, false);
			changeWorldChild2State = CHANGE_WORLDCHILD2_STATE_CAMERA_MOVE_OFFICAL;
		}
		break;
	case CHANGE_WORLDCHILD2_STATE_CAMERA_MOVE_OFFICAL:
		CAMERA->setDx(1);
		PLAYER->setVx(0);
		PLAYER->setDx(0);
		if (CAMERA->getLeft() > getRight())
		{
			setOnChangeWorldChildGate(false);
			WORLD_CHILD_MANAGER->setCurrentWorldChild(currentWorldChild);
			SCOREBAR->setCurrentStageNumber(SCOREBAR->getCurrentStageNumber() + 1);
		}
		break;
	default:
		break;
	}

	vector<BaseObject*> allObjectsHaveToWork = grid->getAllObjectsHaveToWork();
	for (size_t i = 0; i < allObjectsHaveToWork.size(); i++) {
		Collision::CheckCollision(PLAYER, allObjectsHaveToWork[i]);
	}

	if (getIsAllowUpdate() && getIsAllowRender()) {
		update(dt);
	}

	CAMERA->moveX(CAMERA->getDx());
	PLAYER->update(dt);
}

void Gate2::onIntersection(BaseObject * other)
{
	if (other == PLAYER && !getIsAllowUpdate() && !getIsAllowRender()) {
		setOnChangeWorldChildGate(true);
		changeWorldChild2State = CHANGE_WORLDCHILD2_STATE::CHANGE_WORLDCHILD2_STATE_CAMERA_MOVE_TEMP;
	}
}

void Gate2::onReborn()
{
	setToInitLocation();
}




Gate2::~Gate2()
{
}
