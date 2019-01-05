#pragma once
#include "BaseObject.h"

enum MORNING_STAR_TYPE {
	MORNING_STAR_TYPE_1,
	MORNING_STAR_TYPE_2,
	MORNING_STAR_TYPE_3,

	MORNING_STAR_TYPE_COUNT
};


class MorningStar
	: public BaseObject
{
private:
	MORNING_STAR_TYPE currentType;
	static MorningStar* instance;
public:
	static MorningStar* getInstance();
	void growUpMorningStar();
	MORNING_STAR_TYPE getCurrentType();
	void setCurrentType(MORNING_STAR_TYPE currentType);
	void setAction(int action) override;
	void onUpdate(float dt) override;
	void render(Camera* camera) override;

	MorningStar();
	~MorningStar();
};
