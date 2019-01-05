#include "FrameAnimation.h"

FrameAnimation::FrameAnimation()
{
	anchorX = 0;
	anchorY = 0;	
}

int FrameAnimation::getAnchorX()
{
	return anchorX;
}

int FrameAnimation::getAnchorY()
{
	return anchorY;
}

void FrameAnimation::setAnchorX(int anchorX)
{
	this->anchorX = anchorX;
}

void FrameAnimation::setAnchorY(int anchorY)
{
	this->anchorY = anchorY;
}

FrameAnimation::~FrameAnimation()
{
}
