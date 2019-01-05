#include "Gate1.h"
#include "Player.h"
#include "ScoreBar.h"



void Gate1::onIntersection(BaseObject * other)
{
	if (other == PLAYER) {
		WORLD_CHILD_MANAGER->setCurrentWorldChild(1);
		WORLD_CHILD_MANAGER->resetLocationInWorldChild();
		SCOREBAR->setCurrentStageNumber(SCOREBAR->getCurrentStageNumber() + 1);
	}
}

Gate1::Gate1()
{
}


Gate1::~Gate1()
{
}
