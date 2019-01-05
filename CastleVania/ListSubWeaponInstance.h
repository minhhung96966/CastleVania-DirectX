#pragma once
#include "SubWeapon.h"

class ListSubWeaponInstance
{
	static vector<SubWeapon*>* list;
public:
	static vector<SubWeapon*>* getListSupWeapon();
	static void deleteObjectInList();
	
	ListSubWeaponInstance();
	~ListSubWeaponInstance();
};

