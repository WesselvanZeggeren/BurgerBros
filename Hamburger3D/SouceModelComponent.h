#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class SouceModelComponent : public ModelComponent
{
public:
	SouceModelComponent();
	~SouceModelComponent();

	virtual void draw() override;
};