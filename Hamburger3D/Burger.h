#pragma once

#include <vector>
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

	std::vector<GameObject*> ingredients;
	glm::vec3 position = glm::vec3(0, 0, 0);
	glm::vec3 rotation = glm::vec3(0, 0, 0);
	glm::vec3 scale = glm::vec3(1, 1, 1);

public:
	Burger();
	~Burger();


	void addIngriedient(BurgerIngredient* ingredient);
	void addComponent(Component* component);
	void clearBurger();

	double getBurgerModelHeight();
	bool isfinnished();
	bool compareTo(Burger);
	BurgerIngredient* getIngredientByIndex(int index);
	int burgerIngredientCount();

	void update(float elapsedTime);
	void draw(const glm::mat4 & = glm::mat4(1.0f));

	void rebuildBurgerYPos();
	void startAnimation();

	glm::vec3 getPosition();
	void setPosition(glm::vec3 position);
	glm::vec3 getRotation();
	void setRotation(glm::vec3 rotation);
};