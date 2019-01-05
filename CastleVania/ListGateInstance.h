#pragma once
#include "BaseObject.h"
#include "Gate2.h"
class ListGateInstance
{
	static vector<Gate2*>* gateList;
public:
	static vector<Gate2*>* getGateList();
	ListGateInstance();
	~ListGateInstance();
};

