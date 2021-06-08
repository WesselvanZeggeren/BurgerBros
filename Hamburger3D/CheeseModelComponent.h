#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"
using tigl::Vertex;

#include <vector>

class CheeseModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	CheeseModelComponent();
	CheeseModelComponent(int type);
	~CheeseModelComponent();

	virtual void draw() override;
	double getIngredientHeight() override;
	void setCheeseType(int type);
	virtual std::string getName();
};