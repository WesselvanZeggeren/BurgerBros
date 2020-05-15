#pragma once

#include "ModelComponent.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BaconModelComponent : public BurgerIngradient
{
public:
	BaconModelComponent();
	~BaconModelComponent();


	virtual void draw() override;
	virtual double getIngredientHeight() override;
};