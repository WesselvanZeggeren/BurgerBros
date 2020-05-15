#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CheeseModelComponent : public BurgerIngredient
{
public:
	CheeseModelComponent(int);
	~CheeseModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};