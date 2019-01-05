#include "ExplosionEffect.h"
#include "GraphicsAssetsManager.h"


ExplosionEffect* ExplosionEffect::instance = 0;

ExplosionEffect * ExplosionEffect::getInstance()
{
	if (instance == 0) instance = new ExplosionEffect();
	return instance;
}

void ExplosionEffect::onUpdate(float dt)
{
	effectDelay.update();
	if (effectDelay.isTerminated()) setIsAllowUpdateRender(false, false);
}


ExplosionEffect::ExplosionEffect()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_EXPLOSION_EFFECT));
	setIsAllowUpdateRender(false, false);
	effectDelay.init(700);
}


ExplosionEffect::~ExplosionEffect()
{
}
