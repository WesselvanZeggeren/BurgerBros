#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunCrownModelComponent : public ModelComponent
{
public:
	BunCrownModelComponent();
	~BunCrownModelComponent();


	virtual void draw() override;
};