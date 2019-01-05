#pragma once
#include<Windows.h>

class GameTime
{
	DWORD startTime;
	DWORD tickPerFrame;
	DWORD deltaTime;
public:

	DWORD getStartTime();
	void setStartTime(DWORD startTime);
	DWORD getTickPerFrame();
	void setTickPerFrame(DWORD tickPerFrame);
	void init(DWORD tickPerFrame);
	DWORD getDeltaTime();
	void setDeltaTime(DWORD deltaTime);

	GameTime(void);
	~GameTime(void);

	GameTime(DWORD tickPerFrame);
	virtual bool atTime();
};

