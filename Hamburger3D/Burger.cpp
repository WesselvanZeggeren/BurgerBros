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

	addComponent(ingredient);
}

void Burger::addComponent(Component* component)
{

	GameObject* ingredientObject = new GameObject();
	ingredientObject->addComponent(component);
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
		BurgerIngredient* ingredient = go->getComponent<BurgerIngredient>();
		if (ingredient != nullptr) {
			height += ingredient->getIngredientHeight();
		}
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

void Burger::draw(const glm::mat4& parentMatrix)
{
	glm::mat4 modelMatrix = parentMatrix;
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1, 0, 0));
	modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0, 1, 0));
	modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0, 0, 1));
	modelMatrix = glm::scale(modelMatrix, scale);

	for (auto& o : ingredients)	o->draw(modelMatrix);
}


glm::vec3 Burger::getRotation()
{
	return this->rotation;
}

void Burger::setRotation(glm::vec3 rotation)
{
	this->rotation = rotation;
}

glm::vec3 Burger::getPosition()
{

	return this->position;
}

void Burger::setPosition(glm::vec3 position)
{
	this->position = position;
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
