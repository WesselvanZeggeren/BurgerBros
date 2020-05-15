#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class LetaceModelComponent : public BurgerIngredient
{
public:
	LetaceModelComponent();
	~LetaceModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
};