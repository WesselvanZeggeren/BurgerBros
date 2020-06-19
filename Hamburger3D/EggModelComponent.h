#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class EggModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	EggModelComponent();
	~EggModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();
};