#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunHeelModelComponent : public BurgerIngradient
{
public:
	BunHeelModelComponent();
	~BunHeelModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;

};