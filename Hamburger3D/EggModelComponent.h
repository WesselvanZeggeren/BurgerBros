#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class EggModelComponent : public BurgerIngredient
{
public:
	EggModelComponent();
	~EggModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	std::string getIngredientName() override;
};