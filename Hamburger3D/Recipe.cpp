#include "Recipe.h"

Recipe::Recipe()
{

}

Recipe::~Recipe()
{

}

void Recipe::generateRecipe(int maxAmountIngredients)
{

	std::vector<BurgerIngredient*> baseList = getBaseIngredientList();
	srand(time(0));
	int amountOfIngredients = (rand() % maxAmountIngredients) + 1;

	ingredients.clear();

	for (int i = 0; i < amountOfIngredients; i++)
		ingredients.push_back(baseList[(rand() % baseList.size())]);
	
	ingredients.push_back(new BunCrownModelComponent());
}

void Recipe::print()
{

	// Quinc Pils moet dit doen!!
}

std::vector<BurgerIngredient*> Recipe::getBaseIngredientList()
{

	std::vector<BurgerIngredient*> baseList;

	baseList.push_back(new BaconModelComponent());
	baseList.push_back(new BunHeelModelComponent());
	baseList.push_back(new CheeseModelComponent(1));
	baseList.push_back(new CheeseModelComponent(2));
	baseList.push_back(new CheeseModelComponent(0));
	baseList.push_back(new EggModelComponent());
	baseList.push_back(new LettuceModelComponent());
	baseList.push_back(new PattyModelComponent());
	baseList.push_back(new PickleModelComponent());
	baseList.push_back(new SauceModelComponent(1));
	baseList.push_back(new SauceModelComponent(2));
	baseList.push_back(new SauceModelComponent(0));
	baseList.push_back(new TomatoModelComponent());

	return baseList;
}

Burger Recipe::convertToBurger()
{

	Burger burger;

	for (int i = 0; i < ingredients.size(); i++)
		burger.addIngriedient(ingredients[i]);

	return burger;
}