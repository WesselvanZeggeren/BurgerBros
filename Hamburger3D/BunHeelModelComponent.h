#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunHeelModelComponent : public BurgerIngredient
{
public:
	BunHeelModelComponent();
	~BunHeelModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	double getIngredientRecipeHeight() override;
	std::string getIngredientName() override;
};