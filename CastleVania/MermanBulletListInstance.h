#pragma once
#include "MermanBullet.h"

class MermanBulletListInstance
{
	static vector<MermanBullet*>* bulletList;
public:
	static vector<MermanBullet*>* getBulletList();
	static void deleteObjectInList();
	MermanBulletListInstance();
	~MermanBulletListInstance();
};

