#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CucumberModelComponent : public ModelComponent
{
public:
	CucumberModelComponent();
	~CucumberModelCom
		ponent();

	virtual void draw() override;
};