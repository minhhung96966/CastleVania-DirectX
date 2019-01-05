#pragma once
#include <unordered_map>
#include <d3dx9.h>
#include "Game.h"
#include "FrameAnimation.h"

using namespace std;
class Animation
{
	vector<FrameAnimation*> animation;
public:
	void Add(FrameAnimation* r);
	FrameAnimation* Get(unsigned int i);
	void Render(int x, int y, LPDIRECT3DTEXTURE9 texture, int frame);
	void Update(int& frame);
	int getFrameCount();
	Animation();
	~Animation();
};

