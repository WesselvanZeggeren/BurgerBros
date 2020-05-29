#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class SauceModelComponent : public BurgerIngredient
{
public:
	SauceModelComponent(int);
	~SauceModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	double getIngredientRecipeHeight() override;
	std::string getIngredientName() override;
};