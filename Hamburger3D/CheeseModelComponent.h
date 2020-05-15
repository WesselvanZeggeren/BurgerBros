#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CheeseModelComponent : public ModelComponent
{
public:
	CheeseModelComponent();
	~CheeseModelComponent();

	virtual void draw() override;
};