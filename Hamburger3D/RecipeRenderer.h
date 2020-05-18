#pragma once

#include <list>
#include "BaconModelComponent.h"
#include "BunCorwnModelComponent.h"
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

class RecipeRenderer
{
public:
	RecipeRenderer();
	~RecipeRenderer();

	void printRecipe(std::list<BurgerIngredient*> recipe);
};

