#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class TomatoModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	TomatoModelComponent();
	~TomatoModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();
};
