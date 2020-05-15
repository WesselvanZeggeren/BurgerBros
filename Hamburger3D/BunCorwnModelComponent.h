#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunCrownModelComponent : public BurgerIngredient
{
public:
	BunCrownModelComponent();
	~BunCrownModelComponent();


	virtual void draw() override;
	virtual double getIngredientHeight() override;
};