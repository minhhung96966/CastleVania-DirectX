#pragma once
#include <dinput.h>
/*
Abstract class to define keyboard event handlers
*/

class KeyEventHandler
{
public:
	virtual void KeyState(BYTE *state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
};



