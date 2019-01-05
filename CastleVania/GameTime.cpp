#include "GameTime.h"


GameTime::GameTime(void)
{
}

GameTime::GameTime(DWORD tickPerFrame)
{
	this->tickPerFrame = tickPerFrame;
}


bool GameTime::atTime()
{
	DWORD now = GetTickCount();
	
	deltaTime = now - startTime;
	
	if (deltaTime >= tickPerFrame)
	{
		startTime = GetTickCount();
		
		return true;
	}
	
	return false;
}

GameTime::~GameTime(void)
{
}

DWORD GameTime::getStartTime()
{
	return startTime;
}
void GameTime::setStartTime(DWORD startTime)
{
	this->startTime = startTime;
}
DWORD GameTime::getTickPerFrame()
{
	return tickPerFrame;
}
void GameTime::setTickPerFrame(DWORD tickPerFrame)
{
	this->tickPerFrame = tickPerFrame;
}
void GameTime::init(DWORD tickPerFrame)
{
	setTickPerFrame(tickPerFrame);
}
DWORD GameTime::getDeltaTime()
{
	return deltaTime;
}
void GameTime::setDeltaTime(DWORD deltaTime)
{
	this->deltaTime = deltaTime;
}
