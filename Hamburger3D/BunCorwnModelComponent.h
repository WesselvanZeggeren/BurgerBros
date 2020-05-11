#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunVrownModelComponent : public ModelComponent
{
	std::vector<Vertex> verts;
public:
	BunVrownModelComponent();
	~BunVrownModelComponent();


	virtual void draw() override;
};