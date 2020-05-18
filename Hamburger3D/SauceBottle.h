#pragma once

#include "ModelComponent.h"

#include "tigl.h"
using tigl::Vertex;

#include <vector>

class SauceBottle : public ModelComponent
{

public:
	SauceBottle();
	SauceBottle(int type);
	~SauceBottle();

	virtual void draw() override;
	void setSauseType(int type);

};