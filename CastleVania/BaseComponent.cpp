#include "BaseComponent.h"
#include"BaseObject.h"


void BaseComponent::setObjectBody(BaseObject * objectBody)
{
	this->objectBody = objectBody;
}

void BaseComponent::init()
{
}

void BaseComponent::update(float dt)
{
}

void BaseComponent::render(Camera* camera)
{
}

BaseComponent::BaseComponent(BaseObject* objectBody)
{
	setObjectBody(objectBody);
}


BaseComponent::~BaseComponent()
{
}
