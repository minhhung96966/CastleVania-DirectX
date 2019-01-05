#include "MermanBulletListInstance.h"
#include "Collision.h"
#include "Camera.h"

vector<MermanBullet*>* MermanBulletListInstance::bulletList = 0;
vector<MermanBullet*>* MermanBulletListInstance::getBulletList()
{
	if (bulletList == 0)
	{
		bulletList = new vector<MermanBullet*>();
	}
	return bulletList;
}

void MermanBulletListInstance::deleteObjectInList()
{
	for (int i = 0; i < bulletList->size(); i++) {
		if (!Collision::AABBCheck(bulletList->at(i), CAMERA) || bulletList->at(i)->isRemove) {
			auto mermanBulltet = bulletList->at(i);
			bulletList->erase(bulletList->begin() + i);
			delete mermanBulltet;
			i--;
		}
	}
}

MermanBulletListInstance::MermanBulletListInstance()
{
}


MermanBulletListInstance::~MermanBulletListInstance()
{
}
