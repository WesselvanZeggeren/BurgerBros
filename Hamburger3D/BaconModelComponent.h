#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BaconModelComponent : public ModelComponent
{
public:
	BaconModelComponent();
	~BaconModelComponent();


	virtual void draw() override;
};