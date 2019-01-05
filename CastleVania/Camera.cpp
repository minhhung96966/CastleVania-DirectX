#include "Camera.h"
#include "Player.h"
#include "Gate2.h"




Camera* Camera::instance = 0;

Camera * Camera::getInstance()
{
	if (instance == 0) instance = new Camera();
	return instance;
}

void Camera::convertWorldToView(float xWorld, float yWorld, float & xView, float & yView)
{
	D3DXMATRIX matrixWorldToView;
	D3DXMatrixIdentity(&matrixWorldToView);
	matrixWorldToView._22 = -1;
	matrixWorldToView._41 = -this->getX();
	matrixWorldToView._42 = this->getY();

	D3DXVECTOR3 pos3(xWorld, yWorld, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrixWorldToView);

	xView = MatrixResult.x;
	yView = MatrixResult.y;
}

void Camera::update()
{
	setDx(0);

	if (PLAYER->getDx() < 0 && getMidX() > PLAYER->getMidX())
		setDx(PLAYER->getDx());
	
	if (PLAYER->getDx() > 0 && getMidX() < PLAYER->getMidX())
		setDx(PLAYER->getDx());
	
	worldChild = WORLD_CHILD_MANAGER->getCurrentWorldChild();

	// nếu camera chạy sang trái và vượt quá góc trái worldChild
	if (getX() + getDx() < worldChild->x && getDx() < 0)
	{
		setX(worldChild->x);
		setDx(0);
	}

	// nếu camera chạy sang phải và vượt quá góc phải worldChild
	if (getRight() + getDx() > worldChild->x + worldChild->width && getDx() > 0)
	{
		setX(worldChild->x + worldChild->width - getWidth());
		setDx(0);
	}

	// nếu player chạy sang trái và vượt quá góc trái worldChild
	if (PLAYER->getX() + PLAYER->getDx() < worldChild->x && PLAYER->getDx() < 0)
	{
		PLAYER->setX(worldChild->x);
		PLAYER->setDx(0);
	}

	// nếu player chạy sang phải và vượt quá góc phải worldChild
	if (PLAYER->getRight() + PLAYER->getDx() > worldChild->x + worldChild->width && PLAYER->getDx() > 0)
	{
		PLAYER->setX(worldChild->x + worldChild->width - PLAYER->getWidth());
		PLAYER->setDx(0);
	}

	moveX(getDx());
	moveY(getDy());

}



Camera::Camera()
{
}


Camera::~Camera()
{
}
