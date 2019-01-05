#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "debug.h"
#include "KeyEventHandler.h"
#include <dinput.h>

#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_BUFFER_SIZE 1024

class CGame
{
	static CGame * __instance;
	HWND hWnd;									// Window handle

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;			// GraphicsAssets helper library to help us draw 2D image on the screen 


	//---------------------------KEYBOARD-------------------
	
	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	KeyEventHandler* keyHander;

	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data



public:
	void Init(HWND hWnd);
	LPD3DXSPRITE GetSprite();

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	static CGame * GetInstance();

	
	//---------------------------KEYBOARD-------------------
	void InitKeyboard(KeyEventHandler* keyHander);
	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();

	~CGame();
};