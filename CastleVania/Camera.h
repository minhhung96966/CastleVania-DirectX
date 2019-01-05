#pragma once
#include <d3dx9.h>
#include "BaseObject.h"
#include "WorldChildManager.h"

class Camera :
	public BaseObject
{
	static Camera* instance;
	WorldChild* worldChild;
	vector<BaseObject*> allObjectsHaveToWork;
public:
	static Camera* getInstance();
	void convertWorldToView(float xWorld, float yWorld, float& xView, float& yView);
	void update();
	
	Camera();
	~Camera();
};

