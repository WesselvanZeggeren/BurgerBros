#pragma once

#include "ModelComponent.h"
#include <string>

class BurgerIngredient : public ModelComponent {
public:
	virtual void draw() override;
	virtual double getIngredientHeight();
	virtual std::string getName();
};