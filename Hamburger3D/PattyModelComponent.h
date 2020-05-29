#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class PattyModelComponent : public BurgerIngredient
{
public:
	PattyModelComponent();
	~PattyModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	double getIngredientRecipeHeight() override;
	std::string getIngredientName() override;
};