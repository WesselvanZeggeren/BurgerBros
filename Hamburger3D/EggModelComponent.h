#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class EggModelComponent : public BurgerIngradient
{
public:
	EggModelComponent();
	~EggModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};