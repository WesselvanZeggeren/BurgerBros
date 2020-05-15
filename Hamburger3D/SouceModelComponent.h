#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class SouceModelComponent : public BurgerIngradient
{
public:
	SouceModelComponent();
	~SouceModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};