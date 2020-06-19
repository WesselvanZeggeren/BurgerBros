#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CheeseModelComponent : public BurgerIngredient
{
public:
	CheeseModelComponent();
	CheeseModelComponent(int type);
	~CheeseModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	void setCheeseType(int type);
};