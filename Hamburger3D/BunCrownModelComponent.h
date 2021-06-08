#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunCrownModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	BunCrownModelComponent();
	~BunCrownModelComponent();


	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();
};