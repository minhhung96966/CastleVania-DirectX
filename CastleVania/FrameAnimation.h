#pragma once
#include <Windows.h>

class FrameAnimation : public RECT
{
	int anchorX;
	int anchorY;
public:
	int getAnchorX();
	int getAnchorY();
	void setAnchorX(int anchorX);
	void setAnchorY(int anchorY);

	FrameAnimation();
	~FrameAnimation();
};

