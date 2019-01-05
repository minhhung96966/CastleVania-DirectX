#pragma once
#include "BaseObject.h"
#include "Grid.h"

enum CHANGE_WORLDCHILD2_STATE
{
	CHANGE_WORLDCHILD2_STATE_CAMERA_MOVE_TEMP,
	CHANGE_WORLDCHILD2_STATE_GATE_OPENING,
	CHANGE_WORLDCHILD2_STATE_SIMON_MOVE,
	CHANGE_WORLDCHILD2_STATE_GATE_CLOSING,
	CHANGE_WORLDCHILD2_STATE_CAMERA_MOVE_OFFICAL,
};

enum GATE2_ACTION
{
	GATE2_ACTION_OPENING,
	GATE2_ACTION_OPENED,
	GATE2_ACTION_CLOSING
};


class Gate2 :
	public BaseObject
{
	int currentWorldChild;
	boolean onChangeWorldChildGate;
public:
	void onInitFromFile(ifstream& fs, int mapHeight) override;
	void setParam(const char* name, int value);
	CHANGE_WORLDCHILD2_STATE changeWorldChild2State;
	void setOnChangeWorldChildGate(boolean onChangeWorldChildGate);
	boolean getOnChangeWorldChildGate();
	void changeWorldChildInGate(float dt, Grid* grid);
	void onIntersection(BaseObject* other) override;
	void onReborn() override;

	Gate2();
	~Gate2();
};

