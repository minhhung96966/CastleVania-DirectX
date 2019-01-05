#include "Collision.h"
#include<iostream>
#include<string>

using namespace std;
BaseObject * Collision::GetSweptBroadPhaseBox(BaseObject * box)
{
	BaseObject* broadphaseBox = new BaseObject();
	broadphaseBox->setX(box->getDx() > 0 ? box->getX() : (box->getX() + box->getDx()));
	broadphaseBox->setY(box->getDy() > 0 ? (box->getY() + box->getDy()) : box->getY());
	broadphaseBox->setWidth(box->getDx() > 0 ? (box->getWidth() + box->getDx()) : (box->getWidth() - box->getDx()));
	broadphaseBox->setHeight(box->getDy() > 0 ? (box->getHeight() + box->getDy()) : (box->getHeight() - box->getDy()));
	return broadphaseBox;
}

bool Collision::AABBCheck(BaseObject * M, BaseObject * S)
{
	return ((M->getX() < S->getX() + S->getWidth() && M->getX() + M->getWidth() > S->getX()) &&
		(M->getY() - M->getHeight() < S->getY() && M->getY() > S->getY() - S->getHeight()));
}
float Collision::SweptAABB(BaseObject* M, BaseObject* S, float & normalx, float & normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// Tính khoảng cách cần để xảy ra va chạm (InvEntry) và khoảng cách để ra khỏi va chạm (InvExit):
	if (M->getDx() > 0.0f)
	{
		xInvEntry = S->getX() - (M->getX() + M->getWidth());
		xInvExit = (S->getX() + S->getWidth()) - M->getX();
	}
	else
	{
		xInvEntry = (S->getX() + S->getWidth()) - M->getX();
		xInvExit = S->getX() - (M->getX() + M->getWidth());
	}

	if (M->getDy() > 0.0f)
	{
		yInvEntry = S->getY() - S->getHeight() - M->getY();
		yInvExit = S->getY() - (M->getY() - M->getHeight());
	}
	else
	{
		yInvEntry = S->getY() - (M->getY() - M->getHeight());
		yInvExit = (S->getY() - S->getHeight()) - M->getY();
	}

	// Tính thời gian để bắt đầu và chạm và thời gian để kết thúc va chạm theo mỗi phương:
	float xEntry, yEntry;
	float xExit, yExit;

	if (M->getDx() == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / (float)M->getDx();
		xExit = xInvExit / (float)M->getDx();
	}

	if (M->getDy() == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / (float)M->getDy();
		yExit = yInvExit / (float)M->getDy();
	}

	// Thời gian để Box bắt đầu va chạm và thời gian để kết thúc va chạm:
	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	// Trường hợp không xảy ra va chạm:
	//Logger::getInstance()->getWidth()rite_text_to_log_file(std::to_string(GetVy()));
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}

	else // Trường hợp xảy ra va chạm:
	{
		// Xác định hướng của pháp tuyến khi va chạm:
		if (xEntry > yEntry)
		{
			if (M->getDx() < 0.0f) // Chạm vào bề mặt bên phải của block:
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else					// Chạm vào bề mặt bên trái của block:
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			if (M->getDy() < 0.0f) 
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// Trả về khoảng thời gian cần thiết để bắt đầu xảy ra va chạm:
		return entryTime;
	}
}
void Collision::CheckCollision(BaseObject * M, BaseObject * S)
{
	if (M->getIsStopCollision() || S->getIsStopCollision()) return;
	
	BaseObject* broadPhaseBox = GetSweptBroadPhaseBox(M);
	if (AABBCheck(broadPhaseBox, S))
	{
		//Xử lý trường hợp giao nhau
		//Một số trường hợp cần xử lý giao nhau
		if (AABBCheck(M, S))
		{
			M->onIntersection(S);
			S->onIntersection(M);
		}

		delete broadPhaseBox; 
		float normalX = 0, normalY = 0;
		float collisionTime = SweptAABB(M, S, normalX, normalY);
		if (collisionTime < 1)
		{
			M->onCollision(S, collisionTime, normalX, normalY);
			S->onCollision(M, collisionTime, normalX, normalY);
		}

		return;
	}
	delete broadPhaseBox;
}

Collision::Collision()
{
}

Collision::~Collision()
{
}