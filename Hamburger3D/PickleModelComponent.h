#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class PickleModelComponent : public ModelComponent
{
public:
	PickleModelComponent();
	~PickleModelComponent();

	virtual void draw() override;
};