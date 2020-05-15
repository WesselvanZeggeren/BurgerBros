#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class TomatoModelComponent : public ModelComponent
{
public:
	TomatoModelComponent();
	~TomatoModelComponent();

	virtual void draw() override;
};
