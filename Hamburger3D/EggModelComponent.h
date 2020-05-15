#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class EggModelComponent : public ModelComponent
{
public:
	EggModelComponent();
	~EggModelComponent();

	virtual void draw() override;
};