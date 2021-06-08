#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CubeModelComponent : public ModelComponent
{
	std::vector<Vertex> verts;
public:
	CubeModelComponent(float size);
	~CubeModelComponent();


	virtual void draw() override;
};
