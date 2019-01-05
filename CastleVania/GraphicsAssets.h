#pragma once
#include <unordered_map>
#include <d3dx9.h>
#include "Animation.h"
#include "TextureManager.h"
#include <fstream>
#include "GameUtils.h"
#include "FrameAnimation.h"

using namespace std;

class GraphicsAssets
{
	vector<Animation*> animations;
	LPDIRECT3DTEXTURE9 texture;
public:
	int getWidth(int action, int frame);
	int getHeight(int action, int frame);

	void getGraphicsAssetsInfomation(TEXTURE_NAME texture_name, LPCWSTR imagePath , LPCWSTR filePath);
	void Add(Animation* a);
	Animation* getAction(int index);
	void Render(int x, int y, int action, int frame);
	void Update(int action, int& frame);

	GraphicsAssets();
	~GraphicsAssets();
};

