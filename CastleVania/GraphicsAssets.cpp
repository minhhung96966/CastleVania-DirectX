#include "GraphicsAssets.h"
#include "Define.h"

GraphicsAssets::GraphicsAssets()
{
}


void GraphicsAssets::getGraphicsAssetsInfomation(TEXTURE_NAME texture_name ,LPCWSTR imagePath, LPCWSTR filePath)
{
	ifstream fs(filePath);

	ignoreLineIfstream(fs, 2);

	int a, r, g, b;
	fs >> a >> r >> g >> b;

	TextureManager::GetInstance()->Add(texture_name, imagePath, D3DCOLOR_XRGB(r, g, b));

	texture = TEXTURE_MANAGER->Get(texture_name);

	ignoreLineIfstream(fs, 2);

	int numberOfAnimation;
	fs >> numberOfAnimation;

	for (int i = 0; i < numberOfAnimation; i++)
	{
		ignoreLineIfstream(fs, 6);
		Animation* animation = new Animation();

		
		int numberOfFrame;
		fs >> numberOfFrame;

		ignoreLineIfstream(fs, 3);
		for (int i = 0; i < numberOfFrame; i++)
		{
			FrameAnimation* frameAnimation = new FrameAnimation();

			int x, y, width, height, anchorX, anchorY;
			int left, top, right, bottom;
			
			fs >> x >> y >> width >> height >> anchorX >> anchorY;

			left = x; top = y; right = width + x; bottom = y + height;

			SetRect(frameAnimation, left, top, right, bottom);
			frameAnimation->setAnchorX(anchorX);
			frameAnimation->setAnchorY(anchorY);

			animation->Add(frameAnimation);

		}

		Add(animation);
	}

}

void GraphicsAssets::Add(Animation* a)
{
	animations.push_back(a);
}


Animation* GraphicsAssets::getAction(int index)
{
	Animation* ani = animations[index];
	return ani;
}

void GraphicsAssets::Render(int x, int y, int action, int frame)
{
	Animation* ani = getAction(action);
	ani->Render(x, y, texture, frame);
}

void GraphicsAssets::Update(int action, int& frame)
{
	Animation* ani = getAction(action);
	ani->Update(frame);
}

int GraphicsAssets::getWidth(int action, int frame)
{
	return getAction(action)->Get(frame)->right - getAction(action)->Get(frame)->left;
}

int GraphicsAssets::getHeight(int action, int frame)
{
	return getAction(action)->Get(frame)->bottom - getAction(action)->Get(frame)->top;
}




GraphicsAssets::~GraphicsAssets()
{
}
