#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class LetaceModelComponent : public BurgerIngradient
{
public:
	LetaceModelComponent();
	~LetaceModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};