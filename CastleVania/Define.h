#pragma once
#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Castle Vania"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define MAX_FRAME_RATE 120


#define PLAYER_VX 0.06
//#define PLAYER_VX 0.1

#define PLAYER_VY_JUMP 0.21
#define PLAYER_VX_DIE 0.06
#define PLAYER_VY_DIE 0.1

#define OBJECT_GRAVITY -0.00055
#define PLAYER_STAIR_DX 1
#define PLAYER_STAIR_DY 1

#define ZOOMBIE_VX 0.09
#define ZOOMBIE_DETECT_PLAYER_DISTANCE 250

#define PANTHER_VX 0.09
#define PANTHER_VY 0.15
#define PANTHER_DETECT_PLAYER_DISTANCE 50

#define DISTANCE_Y_PLAYER_MERMAN 130
#define DISTANCE_X_PLAYER_MERMAN 75
#define MERMAN_Y_IN_WATER 97

#define MERMAN_RUN_HEIGHT 32
#define MERMAN_FIRE_HEIGHT 30
#define MERMAN_VY_JUMP 0.35
#define MERMAN_VX 0.05
#define MERMAN_BULLET_VX 0.1

#define BOSS_WAIT_TIME 1000
#define BOSS_DISTANCE_ACTIVE 50
#define BOSS_MOVE_FAST_TIME_MIN 1000
#define BOSS_MOVE_FAST_TIME_MAX 2000
#define BOSS_MOVE_SLOW_TIME_MIN 1000
#define BOSS_MOVE_SLOW_TIME_MAX 2000
#define BOSS_AY 0.0001
#define VAMPIRE_BAT_FAST_VX 0.15
#define VAMPIRE_BAT_SLOW_VX 0.09

#define PLAYER_NORMAL_HEIGHT 30
#define PLAYER_SEAT_HEIGHT 23
#define PLAYER_DEAD_HEIGHT 15
#define PLAYER_WIDTH 16

#define VX_WATER 0.04
#define VY_WATER 0.15

#define VX_THE_AX 0.05
#define VY_THE_AX 0.25

#define VX_HOLYWATER 0.05
#define VY_HOLYWATER 0.25

#define MORNING_STAR_TYPE_1_WIDTH 24
#define MORNING_STAR_TYPE_2_WIDTH 23
#define MORNING_STAR_TYPE_3_WIDTH 42

#define MORNING_STAR_TYPE_1_HEIGHT 6
#define MORNING_STAR_TYPE_2_HEIGHT 6
#define MORNING_STAR_TYPE_3_HEIGHT 6

#define GRAPHICS_ASSETS_MANAGER GraphicsAssetsManager::getInstance()
#define PLAYER Player::getInstance()
#define MORNING_STAR MorningStar::getInstance()
#define CAMERA Camera::getInstance()
#define EXPLOSION_EFFECT ExplosionEffect::getInstance()
#define TEXTURE_MANAGER TextureManager::GetInstance()
#define GAME CGame::GetInstance()
#define OBJECT_TAG_GROUP_MANAGER ObjectTagGroupManager::getInstance()
#define GRID Grid::getInstance()
#define WORLD_CHILD_MANAGER WorldChildManager::getInstance()
#define SCOREBAR ScoreBar::getInstance()
#define VAMPIRE_BAT VampireBat::getInstance()
#define LEVEL Level::getInstance()
#define ITEM_END_GAME ItemEndGame::getInstance()

enum OBJECT_DIRECTION
{
	RIGHT = 0,
	LEFT = 1
};