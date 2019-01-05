#include "ListSubWeaponInstance.h"
#include "Collision.h"
#include "Camera.h"

vector<SubWeapon*>* ListSubWeaponInstance::list = NULL;

vector<SubWeapon*>* ListSubWeaponInstance::getListSupWeapon()
{
	if (list == NULL) {
		list = new vector<SubWeapon*>();
	}
	return list;
}



void ListSubWeaponInstance::deleteObjectInList()
{
	{
		for (int i = 0; i < list->size(); i++) {
			if (!Collision::AABBCheck(list->at(i), CAMERA) || list->at(i)->isRemove) {
				auto subWeapon = list->at(i);
				list->erase(list->begin() + i);
				delete subWeapon;
				i--;
			}
		}
	}
}

ListSubWeaponInstance::ListSubWeaponInstance()
{
}


ListSubWeaponInstance::~ListSubWeaponInstance()
{
}
