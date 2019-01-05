#include "BaseObject.h"
#include "Camera.h"
#include"Player.h"
#include<map>
using namespace std;



BaseObject::BaseObject()
{
	gameTime.init(100);
	setGraphicsAssets(NULL);
	set(0, 0, 0, 0);
	setDx(0);
	setDy(0);
	setAx(0);
	setAy(OBJECT_GRAVITY);
	setIsAllowUpdateRender(true, true);
	setPhysicsEnable(false);
}

void BaseObject::onInitFromFile(ifstream & fs, int mapHeight)
{
	int object_tag, x, y, width, height;
	fs >> object_tag >> x >> y >> width >> height;
	/* do y của đối tượng trong file là tọa độ hướng từ trên xuống
	Nhưng y của game chúng ta làm thì gốc tọa độ bên dưới nên ta chuyển nó về cho đúng tọa độ logic */
	y = mapHeight - y;
	initX = x;
	initY = y;
	set(x, y, width, height);
	setObjectTag((OBJECT_TAG)object_tag);
}

void BaseObject::moveX(float dx)
{
	setX(getX() + dx);
}

void BaseObject::moveY(float dy)
{
	setY(getY() + dy);
}

void BaseObject::move(float dx, float dy)
{
	moveX(dx);
	moveY(dy);
}

float BaseObject::getX()
{
	return this->x;
}

float BaseObject::getInitX()
{
	return initX;
}


float BaseObject::getY()
{
	return this->y;
}

float BaseObject::getInitY()
{
	return initY;
}


float BaseObject::getWidth()
{
	return this->width;
}

float BaseObject::getHeight()
{
	return this->height;
}

void BaseObject::setX(float x)
{
	this->x = (int)(x + 0.5);
}

void BaseObject::setY(float y)
{
	this->y = (int)(y + 0.5);
}

void BaseObject::setToInitLocation()
{
	setX(initX);
	setY(initY);
}

void BaseObject::onReborn()
{
	setToInitLocation();
	setIsAllowUpdateRender(true, true);
}

void BaseObject::setWidth(float width)
{
	this->width = width;
}

void BaseObject::setHeight(float height)
{
	this->height = height;
}

void BaseObject::set(float x, float y, float width, float height)
{
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
}

float BaseObject::getLeft()
{
	return x;
}

float BaseObject::getRight()
{
	return x + width;
}

float BaseObject::getTop()
{
	return y;
}

float BaseObject::getBottom()
{
	return y - height;
}

float BaseObject::getMidX()
{
	return x + width / 2;
}

float BaseObject::getMidY()
{
	return y - height / 2;
}

void BaseObject::setDx(float dx)
{
	this->dx = dx;
}

void BaseObject::setDy(float dy)
{
	this->dy = dy;
}

float BaseObject::getDx()
{
	return dx;
}

float BaseObject::getDy()
{
	return dy;
}

float BaseObject::getAx()
{
	return ax;
}

float BaseObject::getAy()
{
	return ay;
}

float BaseObject::getVx()
{
	return vx;
}

float BaseObject::getVy()
{
	return vy;
}

void BaseObject::setAx(float ax)
{
	this->ax = ax;
}

void BaseObject::setAy(float ay)
{
	this->ay = ay;
}

void BaseObject::setVx(float vx)
{
	this->vx = vx;
}

void BaseObject::setVy(float vy)
{
	this->vy = vy;
}

void BaseObject::setPhysicsEnable(bool physicsEnable)
{
	this->physicsEnable = physicsEnable;
}

bool BaseObject::getPhysicsEnable()
{
	return this->physicsEnable;
}



void BaseObject::setGraphicsAssets(GraphicsAssets * graphicsAssets)
{
	this->graphicsAssets = graphicsAssets;
}

GraphicsAssets * BaseObject::getGraphicsAssets()
{
	return this->graphicsAssets;
}

bool BaseObject::getPauseAnimation()
{
	return this->pauseAnimation;
}

void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::getIsLastFrameAnimationDone()
{
	return this->isLastFrameAnimationDone;
}

void BaseObject::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	this->isLastFrameAnimationDone = isLastFrameAnimationDone;
}

void BaseObject::setIsGrounded(bool grounded)
{
	this->grounded = grounded;
}

bool BaseObject::isGrounded()
{
	return this->grounded;
}

void BaseObject::setIsStopCollision(bool isStopCollision)
{
	this->isStopCollision = isStopCollision;
}

bool BaseObject::getIsStopCollision()
{
	return this->isStopCollision;
}

void BaseObject::setIsAllowUpdateRender(bool isAllowUpdate, bool isAllowRender)
{
	this->isAllowUpdate = isAllowUpdate;
	this->isAllowRender = isAllowRender;
}

bool BaseObject::getIsAllowUpdate()
{
	return this->isAllowUpdate;
}

bool BaseObject::getIsAllowRender()
{
	return this->isAllowRender;
}

void BaseObject::setDir(OBJECT_DIRECTION dir)
{
	this->direction = dir;
}

OBJECT_DIRECTION BaseObject::getDir()
{
	return direction;
}


int BaseObject::getAction()
{
	return action;
}

void BaseObject::setAction(int action)
{
	/* nếu set khác animation thì cho chạy lại từ frame 0 */
	if (this->action != action) setFrame(0);
	this->action = action;
}

int BaseObject::getFrame()
{
	return frame;
}

void BaseObject::setFrame(int frame)
{
	this->frame = frame;
}

void BaseObject::onCollision(BaseObject * other, float collisionTime, int nx, int ny)
{
	if (other->getObjectTag() == OBJECT_TAG_GROUND)
	{
		if (ny == 1)
		{
			if (getVy() < 0)
			{
				setVy(-0.2);
			}
			setIsGrounded(true);
		}
		preventMovementWhenCollision(collisionTime, nx, ny);
	}
}

void BaseObject::preventMovementWhenCollision(float collisionTime, int nx, int ny)
{
	//dời M về sát S
	if (nx != 0) setDx(collisionTime*getDx()); //va chạm theo phương x
	if (ny != 0) setDy(collisionTime*getDy()); //va chạm theo phương y
}

void BaseObject::onUpdate(float dt)
{
	setPauseAnimation(false);
	if (getPhysicsEnable())
	{
		// v = v0 + at
		setVx(getVx() + getAx()*dt);
		setVy(getVy() + getAy()*dt);
		// x = x0 + vx*t = x0 + dx => dx = vx*t
		setDx(getVx()*dt);
		setDy(getVy()*dt);

	}
	if (getDy() > 0) setIsGrounded(false);
}

void BaseObject::update(float dt)
{
	if (!getIsAllowUpdate()) return;

	moveX(dx);
	moveY(dy);

	setIsLastFrameAnimationDone(false);

	if (!pauseAnimation && getGraphicsAssets() != NULL) {
		if (gameTime.atTime()) {
			graphicsAssets->Update(action, frame);
			if (frame == 0) {
				setIsLastFrameAnimationDone(true);
			}

		}
	}

	onUpdate(dt);
}

void BaseObject::render(Camera * camera)
{
	if (!getIsAllowRender()) return;

	if (getGraphicsAssets() == 0) {
		return;
	}
	float xView, yView;
	camera->convertWorldToView(getX(), getY(), xView, yView);
	graphicsAssets->Render(xView, yView, action, frame);
}

OBJECT_TAG BaseObject::getObjectTag()
{
	return object_tag;
}

void BaseObject::setObjectTag(OBJECT_TAG object_tag)
{
	this->object_tag = object_tag;
}

void BaseObject::onIntersection(BaseObject * other)
{
}


BaseObject::~BaseObject()
{
}