#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class SauceModelComponent : public BurgerIngredient
{
public:
	SauceModelComponent();
	SauceModelComponent(int type);
	~SauceModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	void setSauseType(int type);
	virtual std::string getName();
};