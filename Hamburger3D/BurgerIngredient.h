#pragma once

#include "ModelComponent.h"

class BurgerIngredient : public ModelComponent {
public:
	virtual void draw() override;
	virtual double getIngredientHeight();
};