#include "Torch.h"
#include "GraphicsAssetsManager.h"


Torch::Torch()
{
	setGraphicsAssets(GRAPHICS_ASSETS_MANAGER->getGraphicsAssets(SPRITE_INFO_TORCH));
	setPhysicsEnable(true);
	setIsAllowUpdateRender(true, true);
	setIsPreviousTriggerMorningStar(false);
}


Torch::~Torch()
{
}
