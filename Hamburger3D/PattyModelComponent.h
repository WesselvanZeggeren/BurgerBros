#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class PattyModelComponent : public BurgerIngradient
{
public:
	PattyModelComponent();
	~PattyModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};