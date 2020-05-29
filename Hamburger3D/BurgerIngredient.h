#pragma once

#include <string>
#include <iostream>

#include "ModelComponent.h"

class BurgerIngredient : public ModelComponent {
protected:
	std::string ingredientName;
public:
	virtual void draw() override;
	virtual double getIngredientHeight();
	virtual double getIngredientRecipeHeight();
	virtual std::string getIngredientName();
};