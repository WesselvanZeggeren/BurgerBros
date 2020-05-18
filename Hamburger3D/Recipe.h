#pragma once

#include <vector>
#include <random>
#include "Burger.h"
#include "BurgerIngredient.h"

class Recipe
{

private:
	std::vector<BurgerIngredient*> ingredients;
	std::vector<BurgerIngredient*> getBaseIngredientList();

public:
	Recipe();
	~Recipe();

	void generateRecipe(int maxAmountIngredients = 10);
	void print();
	
	Burger convertToBurger();
};