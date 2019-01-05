#pragma once
#include "BaseObject.h"

class GiftBox : public BaseObject
{
	bool isPreviousTriggerMorningStar;
public:
	void setIsPreviousTriggerMorningStar(bool isPreviousTriggerMorningStar);
	bool getIsPreviousTriggerMorningStar();
	void onIntersection(BaseObject* other) override;
	void onReborn() override;
	GiftBox();
	~GiftBox();
};

