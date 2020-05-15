#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class LettuceModelComponent : public BurgerIngredient
{
public:
	LettuceModelComponent();
	~LettuceModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};