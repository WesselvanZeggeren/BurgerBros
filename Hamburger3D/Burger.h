#pragma once

#include <list>
#include "BaconModelComponent.h"
#include "BunCrownModelComponent.h"
#include "BunHeelModelComponent.h"
#include "CheeseModelComponent.h"
#include "CubeModelComponent.h"
#include "EggModelComponent.h"
#include "LettuceModelComponent.h"
#include "PattyModelComponent.h"
#include "PickleModelComponent.h"
#include "SauceModelComponent.h"
#include "TomatoModelComponent.h"
#include "LettuceModelComponent.h"

class Burger 
{

private:

	std::list<GameObject*> ingredients;
	std::list<GameObject*> recipeIngredients;

public:
	Burger();
	~Burger();


	void addIngriedient(BurgerIngredient* ingredient);
	void addIngredientToRecipe(BurgerIngredient* ingredient);
	void clearBurger();
	double getBurgerModelHeight();
	double getBurgerModelRecipeHeight();

	void update(float elapsedTime);
	void draw();
};