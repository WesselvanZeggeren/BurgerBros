#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class UnionModelComponent : public BurgerIngredient
{
public:
	UnionModelComponent();
	~UnionModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
}; 
