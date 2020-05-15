#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class UnionModelComponent : public ModelComponent
{
public:
	UnionModelComponent();
	~UnionModelComponent();

	virtual void draw() override;
}; 
