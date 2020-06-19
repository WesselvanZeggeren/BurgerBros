#pragma once

#include "ModelComponent.h"
#include <string>

class BurgerIngredient : public ModelComponent {
private:
	 std::string name;
public:
	virtual void draw() override;
	virtual double getIngredientHeight();
	virtual std::string getName();
};