#pragma once
class BaseObject;
class Camera;
class BaseComponent
{
protected:
	BaseObject* objectBody;
public:
	
	void setObjectBody(BaseObject* objectBody);
	virtual void init();
	virtual void update(float dt);
	virtual void render(Camera* camera);
	BaseComponent(BaseObject* objectBody);
	~BaseComponent();
};

