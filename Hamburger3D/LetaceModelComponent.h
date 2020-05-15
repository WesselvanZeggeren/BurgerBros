#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class LetaceModelComponent : public ModelComponent
{
public:
	LetaceModelComponent();
	~LetaceModelComponent();

	virtual void draw() override;
};