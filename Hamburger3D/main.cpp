#include "Game.h"
#include "Camera.h"

using namespace cv;
using namespace std;

Game game;
Camera camera;

int main(void)
{
	/*
	if (0)
	{
		game.startGame(camera.height, camera.width, camera);
		return 0;

	}
	else 
	{
		
		return 0;
	}
	*/

	Recipe recipe;
	Burger burger1;
	Burger burger2;
	Burger burger3;

	recipe.generateRecipe();

	//2 of the same burger
	burger1 = recipe.convertToBurger();
	burger2 = recipe.convertToBurger();

	recipe.generateRecipe();

	//different burger
	burger3 = recipe.convertToBurger();

	//should return true
	std::cout << burger1.compareTo(burger2) << "\n";

	//should return false
	std::cout << burger1.compareTo(burger3) << "\n";

	

}
