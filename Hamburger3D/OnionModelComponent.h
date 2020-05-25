#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class OnionModelComponent : public BurgerIngredient
{
public:
	OnionModelComponent();
	~OnionModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	std::string getIngredientName() override;
}; 
