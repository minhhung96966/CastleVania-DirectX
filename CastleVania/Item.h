#pragma once
#include "BaseObject.h"
class Item :
	public BaseObject
{
	bool isPreviousTriggerMorningStar;
public:
	void setIsPreviousTriggerMorningStar(bool isPreviousTriggerMorningStar);
	bool getIsPreviousTriggerMorningStar();
	void onIntersection(BaseObject* other) override;
	virtual void onContactPlayer();
	void onReborn() override;
	Item();
	~Item();
};

