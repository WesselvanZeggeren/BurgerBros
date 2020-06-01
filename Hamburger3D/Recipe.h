#pragma once

#include <vector>
#include <random>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h>
#include "Burger.h"
#include "BurgerIngredient.h"

class Recipe
{

protected:
	std::vector<BurgerIngredient*> ingredients;
	std::vector<BurgerIngredient*> getBaseIngredientList();

public:
	Recipe();
	~Recipe();

	void generateRecipe(int maxAmountIngredients = 15);
	virtual void print();
	
	Burger convertToBurger();
};