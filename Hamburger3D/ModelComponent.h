#pragma once

#include "Component.h"
#include "ShapeMaker.h"

class ModelComponent : public Component
{
public:
	ModelComponent();
	~ModelComponent();
	virtual void draw() = 0;
protected:
	ShapeMaker model;
};