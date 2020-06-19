#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <thread>

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"

#include "tigl.h"
#include "GameObject.h"
#include "Burger.h"
#include "Recipe.h"
#include "SauceBottle.h"

#include "CubeModelComponent.h"
#include "SpinComponent.h"
#include "BunCrownModelComponent.h"
#include "ScreenMOdelComponent.h"

#include "SimpleTrashBin.h"

#include "Camera.h"

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

using tigl::Vertex;
using namespace cv;

class Game
{

private:
	GLFWwindow* window;
	GLuint textureId = 0;

	void init();
	void drawGame();
	void drawMainMenu();
	void update();

	void setScreen();
	void setIngredients();

public:
	std::list<GameObject*> objects;
	std::list<GameObject*> ingredients;
	
	GameObject* screen;
	Recipe animatedRecipe;
	Burger animatedBurger;

	double lastFrameTime;
	glm::vec2 pixelToOpenGL(glm::vec2 pos);

	void manageHandToIngredientPosition();

	void bindIngredient(glm::vec2 position);
	void bindToBurger(glm::vec2 position);

	void startGame(double height, double width, Camera cam);
	void setFrame(Mat& frame);

};
