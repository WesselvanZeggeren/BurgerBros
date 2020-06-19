#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class BunHeelModelComponent : public BurgerIngredient
{
private:
	std::string name;

public:
	BunHeelModelComponent();
	~BunHeelModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();

};