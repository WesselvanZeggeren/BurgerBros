#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class ScreenMOdelComponent : public ModelComponent
{
	std::vector<Vertex> verts;
public:
	ScreenMOdelComponent();
	~ScreenMOdelComponent();


	virtual void draw() override;
};
