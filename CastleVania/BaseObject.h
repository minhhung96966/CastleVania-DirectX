#pragma once
#include "GameTime.h"
#include "GraphicsAssets.h"
#include "Define.h"
#include "debug.h"
#include "ObjectTagGroupManager.h"


class Camera;

class BaseObject
{
	float x, y, width, height, dx, dy, ax, ay, vx, vy, initX, initY;

	GraphicsAssets* graphicsAssets;
	int action, frame;

	GameTime gameTime;

	bool physicsEnable, pauseAnimation, isLastFrameAnimationDone, grounded, isStopCollision, isAllowUpdate, isAllowRender;

	OBJECT_DIRECTION direction;

	OBJECT_TAG object_tag;

public:
	virtual void onInitFromFile(ifstream& fs, int mapHeight);

	void moveX(float dx);
	void moveY(float dy);
	void move(float dx, float dy);

	float getX(); float getInitX();
	float getY(); float getInitY();
	float getWidth();
	float getHeight();

	void setX(float x); 
	void setY(float y);
	virtual void setToInitLocation();
	void setWidth(float width);
	void setHeight(float height);

	virtual void onReborn();

	void set(float x, float y, float width, float height);

	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	float getMidX();
	float getMidY();

	virtual void setDx(float dx);
	void setDy(float dy);

	float getDx();
	float getDy();

	float getAx();
	float getAy();
	float getVx();
	float getVy();

	void setAx(float ax);
	void setAy(float ay);
	void setVx(float vx);
	void setVy(float vy);

	void setPhysicsEnable(bool physicsEnable);

	bool getPhysicsEnable();
	
	void setGraphicsAssets(GraphicsAssets* graphicsAssets);
	GraphicsAssets* getGraphicsAssets();

	bool getPauseAnimation();
	void setPauseAnimation(bool pauseAnimation);

	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);

	void setIsGrounded(bool grounded);
	bool isGrounded();

	void setIsStopCollision(bool isStopCollision);
	bool getIsStopCollision();

	
	virtual void setIsAllowUpdateRender(bool isAllowUpdate, bool isAllowRender);
	bool getIsAllowUpdate();
	bool getIsAllowRender();

	void setDir(OBJECT_DIRECTION dir);
	OBJECT_DIRECTION getDir();

	int getAction();
	virtual void setAction(int action);

	int getFrame();
	void setFrame(int frame);

	virtual void onUpdate(float dt);
	void update(float dt);
	virtual void render(Camera* camera);

	OBJECT_TAG getObjectTag();
	void setObjectTag(OBJECT_TAG object_tag);

	virtual void onCollision(BaseObject* other, float collisionTime, int nx, int ny);

	void preventMovementWhenCollision(float collisionTime, int nx, int ny);

	virtual void onIntersection(BaseObject* other);

	BaseObject();
	~BaseObject();
};
