#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class PattyModelComponent : public ModelComponent
{
public:
	PattyModelComponent();
	~PattyModelComponent();

	virtual void draw() override;
};