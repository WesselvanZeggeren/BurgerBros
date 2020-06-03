#pragma once

#include <list>
#include "BaconModelComponent.h"
#include "BunCrownModelComponent.h"
#include "BunHeelModelComponent.h"
#include "CheeseModelComponent.h"
#include "CubeModelComponent.h"
#include "EggModelComponent.h"
#include "CucumberModelComponent.h"
#include "LettuceModelComponent.h"
#include "PattyModelComponent.h"
#include "PickleModelComponent.h"
#include "SauceModelComponent.h"
#include "TomatoModelComponent.h"
#include "LettuceModelComponent.h"

class Burger 
{
public:
	double distanceIngredients = 1;
	bool animate = false;

private:

	std::list<GameObject*> ingredients;
	glm::vec3 position = glm::vec3(0, 0, 0);;

public:
	Burger();
	~Burger();


	void addIngriedient(BurgerIngredient* ingredient);
	void clearBurger();
	double getBurgerModelHeight();
	bool isfinnished();
	BurgerIngredient* getIngredientByIndex(int index);
	int burgerIngredientCount();

	void update(float elapsedTime);
	void draw();
	glm::vec3 getRotation();
	void setRotation(glm::vec3 rotation);
	void rebuildBurgerYPos();
	void startAnimation();
	void setPosition(glm::vec3 position);
};