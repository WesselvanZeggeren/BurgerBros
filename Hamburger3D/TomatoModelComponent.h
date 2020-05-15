#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class TomatoModelComponent : public BurgerIngradient
{
public:
	TomatoModelComponent();
	~TomatoModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};
