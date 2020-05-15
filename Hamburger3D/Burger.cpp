#include "Burger.h"
#include "GameObject.h"
#include "SpinComponent.h"
#include <typeinfo>

Burger::Burger()
{
	addIngriedient(new BunHeelModelComponent());
}

Burger::~Burger()
{
}

void Burger::addIngriedient(BurgerIngredient* ingredient)
{
	GameObject* ingredientObject = new GameObject();
	ingredientObject->addComponent(ingredient);
	ingredientObject->addComponent(new SpinComponent(1));
	ingredientObject->position.y += getBurgerModelHeight();
	ingredients.push_back(ingredientObject);
}

void Burger::clearBurger()
{
	ingredients.clear();
	GameObject* bottomBunn = new GameObject();
	bottomBunn->addComponent(new BunHeelModelComponent());
}

double Burger::getBurgerModelHeight()
{
	double height = 0;
	for (GameObject* go : ingredients) {
		height += go->getComponent<BurgerIngredient>()->getIngredientHeight();
	}
	return height;
}

void Burger::update(float elapsedTime)
{
	for (auto& o : ingredients)
		o->update(elapsedTime);
}

void Burger::draw()
{
	for (auto& o : ingredients)
		o->draw();
}
