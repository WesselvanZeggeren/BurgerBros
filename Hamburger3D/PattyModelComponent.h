#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class PattyModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	PattyModelComponent();
	~PattyModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();
};