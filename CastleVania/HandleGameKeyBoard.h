#pragma once
#include "KeyEventHandler.h"
#include "Player.h"

class HandleGameKeyBoard :
	public KeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
public:
	HandleGameKeyBoard();
};

