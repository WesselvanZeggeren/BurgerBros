#pragma once

#include "BurgerIngredient.h"
#include "tigl.h"

using tigl::Vertex;

#include <vector>

class BaconModelComponent : public BurgerIngredient
{
private:
	std::string name;
public:
	BaconModelComponent();
	~BaconModelComponent();


	virtual void draw() override;
	double getIngredientHeight() override;
	virtual std::string getName();
};