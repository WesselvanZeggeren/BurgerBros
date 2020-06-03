#include "Burger.h"
#include "GameObject.h"
#include "SpinComponent.h"
#include <typeinfo>
#include <iostream>


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
	
	for (GameObject* go : ingredients) 
	{
		height += go->getComponent<BurgerIngredient>()->getIngredientHeight();
	}

	return height;
}

bool Burger::isfinnished()
{
	for (GameObject* go : ingredients) {
		if (dynamic_cast<BunCrownModelComponent*>  (go->getComponent<BurgerIngredient>()) != NULL) {
			return true;
		}
	}
	return false;
}

BurgerIngredient* Burger::getIngredientByIndex(int index)
{ 
	int i = 0;
	for(GameObject* go: ingredients) {
		if (i == index) {
			return go->getComponent<BurgerIngredient>();
		}
		i++;
	}
	return NULL;
}

int Burger::burgerIngredientCount()
{
	return static_cast<int>(ingredients.size());
}

void Burger::update(float elapsedTime)
{
	if (animate) {
		if (distanceIngredients > 1) {
			distanceIngredients -= elapsedTime;
		}
		else {
			distanceIngredients = 1;
			
		}
		rebuildBurgerYPos();
	}



	for (auto& o : ingredients)
		o->update(elapsedTime);
}

void Burger::draw()
{
	for (auto& o : ingredients)	o->draw();
}

glm::vec3 Burger::getRotation()
{
	for (auto& heel : ingredients) {
		return heel->rotation;
	}
}

void Burger::setRotation(glm::vec3 rotation)
{
	for (auto& o : ingredients)
		o->rotation = rotation;
}

void Burger::setPosition(glm::vec3 position)
{
	for (auto& o : ingredients)
		o->position = position;
}


void Burger::rebuildBurgerYPos()
{
	double burgerheight = 0;
	for (auto& ingredient : ingredients) {
		double ingredientHeight = ingredient->getComponent<BurgerIngredient>()->getIngredientHeight();
		ingredient->position.y = burgerheight;
		burgerheight += ingredientHeight + distanceIngredients/10 - 0.1;
	}
}

void Burger::startAnimation()
{
	distanceIngredients = 7;
}
