#pragma once

#include "BurgerIngredient.h"

#include "tigl.h"
using tigl::Vertex;

#include <vector>

class SauceBottle : public BurgerIngredient
{

public:
	SauceBottle();
	SauceBottle(int type);
	~SauceBottle();

	virtual void draw() override;
	void setSauseType(int type);

};