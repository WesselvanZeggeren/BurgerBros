#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunHeelModelComponent : public ModelComponent
{
public:
	BunHeelModelComponent();
	~BunHeelModelComponent();

	virtual void draw() override;
};