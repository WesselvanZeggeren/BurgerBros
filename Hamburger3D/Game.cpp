#include "Game.h"

/**
 * Start game
 */
void Game::startGame(double height, double width, void (*frameCallback)(void))
{

	if (!glfwInit())
		throw "Could not initialize glwf";

	window = glfwCreateWindow(width * 2, height * 2, "Hello World", NULL, NULL);

	if (!window)
	{
	
		glfwTerminate();
		throw "Could not initialize glwf";
	}

	glfwMakeContextCurrent(window);

	tigl::init();
	init();

	while (!glfwWindowShouldClose(window))
	{

		frameCallback();

		update();
		draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

/**
 * Init, Draw & Update
 */
void Game::init()
{

	glEnable(GL_DEPTH_TEST);

	setScreen();
	setIngredients();

	recipe.generateRecipe(10);
	burger = recipe.convertToBurger();

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
	{

		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, true);
	});
}

void Game::update()
{

	double currentFrameTime = glfwGetTime();
	double deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;

	for (auto& o : objects)
		o->update(deltaTime);

	for (auto& i : ingredients)
		i->update(deltaTime);

	burger.update(deltaTime);
}

void Game::draw()
{

	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), viewport[2] / (float)viewport[3], 0.01f, 1000.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setModelMatrix(glm::mat4(1.0f));
	tigl::shader->setViewMatrix(view);

	for (auto& o : objects)
		o->draw();

	for (auto& i : ingredients)
		i->draw();
}

/**
 * Set objects
 */
void Game::setScreen()
{

	GameObject* screen = new GameObject();
	screen->addComponent(new ScreenMOdelComponent());
	screen->position = glm::vec3(0, 0, 0);
	objects.push_back(screen);
}

/**
 * setIngredients & other ingredient functions
 */
void Game::setIngredients()
{

	double x = -12.0;
	double y = 6.0;
	double z = -15.0; 
	double offset = 0;

	int amountInRow = 4;

	std::vector<BurgerIngredient*> baseList = Recipe::getBaseIngredientList(true);

	double distance = std::abs((x * 2) / (amountInRow - 1));

	for (int i = 0; i < baseList.size(); i++)
	{

		double newX = x + (distance * (i % amountInRow)) + offset;
		double newY = y - (3 * std::floor(i / amountInRow));

		GameObject* ingredient = new GameObject();
		ingredient->addComponent(baseList[i]);
		ingredient->position = glm::vec3(newX, newY, z);
		ingredient->rotation.y = 3 * .25f;

		ingredients.push_back(ingredient);
	}

	GameObject* crown = new GameObject();
	crown->addComponent(new BunCrownModelComponent());
	crown->position = glm::vec3(x, y * -1, z);
	crown->rotation.y = 3 * .25f;

	ingredients.push_back(crown);
}

BurgerIngredient Game::getIngredient(Point point)
{

	BurgerIngredient ingredient;

	return ingredient;
}

/**
 * Frame functions
 */
void Game::setFrame(Mat& frame)
{

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGB,
		frame.cols,
		frame.rows,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		frame.data);
}