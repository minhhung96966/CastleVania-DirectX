#include "GraphicsAssetsManager.h"
#include "Define.h"
#include "TextureManager.h"

GraphicsAssetsManager * GraphicsAssetsManager::instance = 0;

GraphicsAssetsManager * GraphicsAssetsManager::getInstance()
{
	if (instance == 0) {
		instance = new GraphicsAssetsManager();
	}

	return instance;
}

GraphicsAssets * GraphicsAssetsManager::getGraphicsAssets(int spriteInfo)
{
	return getInstance()->allGraphicsAssets[spriteInfo];
}

GraphicsAssetsManager::GraphicsAssetsManager()
{
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		allGraphicsAssets.push_back(new GraphicsAssets());
	}

	allGraphicsAssets[SPRITE_INFO_SIMON]->getGraphicsAssetsInfomation(TEXTURE_SIMON, L"Assets/GraphicsAssets/Simon/image.png", L"Assets/GraphicsAssets/Simon/simon_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_MORNING_STAR]->getGraphicsAssetsInfomation(TEXURE_MORNING_STAR, L"Assets/GraphicsAssets/MorningStar/image.png", L"Assets/GraphicsAssets/MorningStar/morning_star_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_ZOOMBIE]->getGraphicsAssetsInfomation(TEXTURE_ZOOMBIE, L"Assets/GraphicsAssets/Zoombie/image.png", L"Assets/GraphicsAssets/Zoombie/zoombie_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_TORCH]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/torch.info.txt");
	allGraphicsAssets[SPRITE_INFO_EXPLOSION_EFFECT]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/ExplosionEffect.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_MORNING_STAR]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Item_morning_star.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_BIG_HEART]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Item_big_heart.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_SMALL_HEART]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Item_small_heart.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_KNIFE]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Item_knife.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_1000PTS]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_1000pts.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_700PTS]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_700pts.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_400PTS]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_400pts.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_HOLYCROSS]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_holycross.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_HOLYWATER]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_holywater.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_THEAX]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Item_the_ax.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_MAGIC_LAMP]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Item_magic_lamp.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_INCREASE_HEALTH]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_increase_health.txt");
	allGraphicsAssets[SPRITE_INFO_ITEM_ENDGAME]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/item_end_game.txt");
	allGraphicsAssets[SPRITE_INFO_CANDLE]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/Candle.txt");
	allGraphicsAssets[SPRITE_INFO_PANTHER]->getGraphicsAssetsInfomation(TEXTURE_PANTHER, L"Assets/GraphicsAssets/Panther/image.png", L"Assets/GraphicsAssets/Panther/panther.info.dat");
	allGraphicsAssets[SPRITE_INFO_GATE2]->getGraphicsAssetsInfomation(TEXTURE_GATE2, L"Assets/GraphicsAssets/Gate2/image.png", L"Assets/GraphicsAssets/Gate2/gate2_infomation.txt");
	allGraphicsAssets[SPRITE_INFO_BRICK]->getGraphicsAssetsInfomation(TEXTURE_BRICK, L"Assets/GraphicsAssets/Brick/image.png", L"Assets/GraphicsAssets/Brick/brick_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_BREAKWALL1]->getGraphicsAssetsInfomation(TEXTURE_BREAKWALL1, L"Assets/GraphicsAssets/BreakWall1/image.png", L"Assets/GraphicsAssets/BreakWall1/BreakWall1_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_BREAKWALL2]->getGraphicsAssetsInfomation(TEXTURE_BREAKWALL2, L"Assets/GraphicsAssets/BreakWall2/image.png", L"Assets/GraphicsAssets/BreakWall2/BreakWall2_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_MERMAN]->getGraphicsAssetsInfomation(TEXTURE_MERMAN, L"Assets/GraphicsAssets/Merman/image.png", L"Assets/GraphicsAssets/Merman/merman_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_MERMAN_BULLET]->getGraphicsAssetsInfomation(TEXTURE_MIXTURE, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/merman_bullet.txt");
	allGraphicsAssets[SPRITE_INFO_WATER]->getGraphicsAssetsInfomation(TEXTURE_WATER, L"Assets/GraphicsAssets/Mixture/mixture.png", L"Assets/GraphicsAssets/Mixture/water.txt");
	allGraphicsAssets[SPRITE_INFO_BAT]->getGraphicsAssetsInfomation(TEXTURE_BAT, L"Assets/GraphicsAssets/Bat/image.png", L"Assets/GraphicsAssets/Bat/bat_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_KNIFE]->getGraphicsAssetsInfomation(TEXTURE_KNIFE, L"Assets/GraphicsAssets/Knife/image.png", L"Assets/GraphicsAssets/Knife/knife_animation.info.dat");
	allGraphicsAssets[SPRITE_INFO_SCOREBAR]->getGraphicsAssetsInfomation(TEXTURE_SCOREBAR_ITEM, L"Assets/GraphicsAssets/Scorebar/image.png", L"Assets/GraphicsAssets/Scorebar/score_bar_animation.txt");
	allGraphicsAssets[SPRITE_INFO_VAMPIREBAT]->getGraphicsAssetsInfomation(TEXTURE_VAMPIREBAT, L"Assets/GraphicsAssets/VampireBat/image.png", L"Assets/GraphicsAssets/VampireBat/vampire_bat_aimation.txt");
	allGraphicsAssets[SPRITE_INFO_THEAX]->getGraphicsAssetsInfomation(TEXTURE_THEAX, L"Assets/GraphicsAssets/TheAx/image.png", L"Assets/GraphicsAssets/TheAx/the_ax_animation.dat");
	allGraphicsAssets[SPRITE_INFO_HOLYWATER]->getGraphicsAssetsInfomation(TEXTURE_HOLYWATER, L"Assets/GraphicsAssets/HolyWater/image.png", L"Assets/GraphicsAssets/HolyWater/holy_water_animation.txt");
	TEXTURE_MANAGER->Add(TEXTURE_SCOREBAR, L"Assets/GraphicsAssets/Scorebar/score_bar.png", D3DCOLOR_XRGB(255,43,232));
}


GraphicsAssetsManager::~GraphicsAssetsManager()
{
}
