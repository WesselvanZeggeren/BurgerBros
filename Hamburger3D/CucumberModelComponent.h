#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CucumberModelComponent : public BurgerIngredient
{
public:
	CucumberModelComponent();
	~CucumberModelComponent();

	virtual void draw() override;
	virtual double getIngredientHeight() override;
};