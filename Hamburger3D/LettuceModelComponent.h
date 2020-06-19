#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class LettuceModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	LettuceModelComponent();
	~LettuceModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();
};