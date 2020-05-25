#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BaconModelComponent : public BurgerIngredient
{
public:
	BaconModelComponent();
	~BaconModelComponent();


	virtual void draw() override;
	double getIngredientHeight() override;
	std::string getIngredientName() override;
};