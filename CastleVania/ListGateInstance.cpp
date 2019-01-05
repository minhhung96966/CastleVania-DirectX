#include "ListGateInstance.h"


vector<Gate2*>* ListGateInstance::gateList = 0;

vector<Gate2*>* ListGateInstance::getGateList()
{
	if (gateList == 0) {
		gateList = new vector<Gate2*>();
	}
	return gateList;
}

ListGateInstance::ListGateInstance()
{
}


ListGateInstance::~ListGateInstance()
{
}
