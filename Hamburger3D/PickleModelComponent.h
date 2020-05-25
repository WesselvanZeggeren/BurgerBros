#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class PickleModelComponent : public BurgerIngredient
{
public:
	PickleModelComponent();
	~PickleModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	std::string getIngredientName() override;
};