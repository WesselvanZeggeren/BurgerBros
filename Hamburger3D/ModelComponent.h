#pragma once

#include "Component.h"

class ModelComponent : public Component
{
public:
	ModelComponent();
	~ModelComponent();
	virtual void draw() = 0;
private:

};