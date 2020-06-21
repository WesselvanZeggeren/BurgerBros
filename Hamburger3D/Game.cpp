#include "Game.h"
#include "Camera.h"
#include "MenuCamera.h"

FpCam* MenuCam;
Camera cam;
GLuint textureId = 0;
bool gameState = false;

bool gameOver = false;

bool selectState;

Burger* buildingBurger;
Burger buildingRecipeBurger;
Recipe* buildingRecipe;

int buildingBurgerIndex = 0;

int score = 0;

double camHeight, camWidth;

/**
 * Start game
 */
void Game::startGame(double height, double width, Camera cam)
{

	if (!glfwInit())
		throw "Could not initialize glwf";

	window = glfwCreateWindow(width * 2, height * 2, "Hello World", NULL, NULL);
	camHeight = height;
	camWidth = width;
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
		update();
		if (animatedBurger.distanceIngredients == 1) { animatedBurger.startAnimation(); }
		if (gameState) {
			drawGame();
		}
		else { drawMainMenu(); }
		if (gameState && glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { endGame(); }
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

/**
 * Init, Draw & Update
 */
GameObject* cursor;

void Game::init()
{
	glEnable(GL_DEPTH_TEST);

	animatedRecipe.generateRecipe(10);
	animatedBurger = animatedRecipe.convertToBurger();
	animatedBurger.setPosition(glm::vec3(0, 0, -4));
	animatedBurger.animate = true;

	buildingRecipe = new Recipe();
	buildingRecipe->generateRecipe(8);
	buildingRecipeBurger = buildingRecipe->convertToBurger();
	buildingRecipeBurger.distanceIngredients = 3;
	buildingRecipeBurger.animate = false;

	cursor = new GameObject();
	cursor->addComponent(new CubeModelComponent(0.1));
	cursor->position.z = -14;
	objects.push_back(cursor);

	setScreen();
	setIngredients();

	stopwatch = new StopWatch();

	textWriter = new TextControl("C:/Windows/Fonts/times.ttf", 20, 1920.0f, 1080.0f);

	buildingBurgerIndex = 1;

	selectState = true;

	tigl::shader->enableColor(true);
	tigl::shader->enableTexture(true);
	tigl::shader->enableAlphaTest(true);

	tigl::shader->enableLighting(true);
	tigl::shader->setLightCount(2);

	tigl::shader->setLightDirectional(0, true);
	tigl::shader->setLightPosition(0, glm::vec3(10, 5, 10));
	tigl::shader->setLightAmbient(0, glm::vec3(1.0f, 1.0f, 1.0f));
	tigl::shader->setLightDiffuse(0, glm::vec3(0.9f, 0.9f, 0.9f));
	tigl::shader->setLightSpecular(0, glm::vec3(1, 1, 1));
	tigl::shader->setShinyness(100.0f);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
	{
		if (key == GLFW_KEY_ENTER) {
			if (selectState)
			{
				buildingBurger->clearBurger();
				buildingBurger->addComponent(new BunHeelModelComponent());
				gameState = true;
				gameOver = false;
			}
			else
			{
				glfwSetWindowShouldClose(window, true);
			}
		}
		if (key == GLFW_KEY_UP && action == GLFW_RELEASE) {
			if (selectState == true) { selectState = false; return; }
			if (selectState == false) { selectState = true; return; }
		}
		if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE ){
			if (selectState == true) { selectState = false; return; }
			if (selectState == false) { selectState = true; return; }
		}
		//This is a temperary testing hotkey
		/*if (key == GLFW_KEY_N) {
			if (buildingBurger->isfinnished()) {
				glm::vec3 rotation = buildingRecipeBurger.getRotation();
				buildingBurger->clearBurger();
				buildingRecipe->generateRecipe(8);
				buildingRecipeBurger = buildingRecipe->convertToBurger();
				buildingRecipeBurger.setPosition(glm::vec3(12, -1.5, -15));
				buildingRecipeBurger.distanceIngredients = 3;
				buildingRecipeBurger.rebuildBurgerYPos();
				buildingRecipeBurger.setRotation(rotation);
			}
			else {
				BurgerIngredient* ingredient = buildingRecipeBurger.getIngredientByIndex(buildingBurger->burgerIngredientCount());
				buildingBurger->addIngriedient(ingredient);
				buildingBurger->setPosition(glm::vec3(0, -8, -15));
				buildingBurger->rebuildBurgerYPos();
			}
		}*/
		if (key == GLFW_KEY_ESCAPE) {
			gameState = false;
			gameOver = false;
			tigl::shader->setLightAmbient(0, glm::vec3(1.0f, 1.0f, 1.0f));
			score = 0;
		}
	});

	MenuCam = new FpCam(window);
}

void Game::update()
{
	Mat frame = cam.SnapShot();
	setFrame(frame);

	double currentFrameTime = glfwGetTime();
	double deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;

	if (gameState) {

		for (auto& o : objects)
			o->update(deltaTime);

		for (auto& i : ingredients)
			i->update(deltaTime);

		buildingRecipeBurger.update(deltaTime);
		
		if (!gameOver)
		{
			manageHandToIngredientPosition();
		}
	}

	if (!gameState)
	{
		animatedBurger.update(deltaTime);
		MenuCam->update(window);
		stopwatch->start();
	}
}


/*
 *	MainMenu draw function
 *	Needs use of objects
 *	TODO: Component use + lightning fix
 */
void Game::drawMainMenu()
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		gameState = true;
	}

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);

	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setViewMatrix(MenuCam->getMatrix());
	tigl::shader->setModelMatrix(glm::mat4(1.0f));

	double y = 0;
	int n = -1;

	tigl::begin(GL_QUADS);
	tigl::addVertex(Vertex::PT(glm::vec3(0, 0, -5), glm::vec2(1, 0)));
	tigl::addVertex(Vertex::PT(glm::vec3(0, 8, -5), glm::vec2(1, -1)));
	tigl::addVertex(Vertex::PT(glm::vec3(8, 8, 0), glm::vec2(0, -1)));
	tigl::addVertex(Vertex::PT(glm::vec3(8, 0, 0), glm::vec2(0, 0)));

	glDisable(GL_TEXTURE_2D);

	tigl::addVertex(Vertex::PCN(glm::vec3(0, y, -8), glm::vec4(1, 1, 1, 1), glm::vec3(0, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(8, y, 0), glm::vec4(1, 1, 1, 1), glm::vec3(0, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0, y, 8), glm::vec4(1, 1, 1, 1), glm::vec3(0, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-8, y, 0), glm::vec4(1, 1, 1, 1), glm::vec3(0, -1, 0)));

	tigl::addVertex(Vertex::PN(glm::vec3(0, 0, -5), glm::vec3(-1, 0, 0)));
	tigl::addVertex(Vertex::PN(glm::vec3(0, 8, -5), glm::vec3(-1, 0, 0)));
	tigl::addVertex(Vertex::PN(glm::vec3(-8, 8, 0), glm::vec3(-1, 0, 0)));
	tigl::addVertex(Vertex::PN(glm::vec3(-8, 0, 0), glm::vec3(-1, 0, 0)));

	tigl::end();
	
	animatedBurger.draw();

	textWriter->setScale(5.0f);
	if (selectState == true)
	{
		textWriter->drawText("> Start Game", -300, -80);
		textWriter->drawText("   Exit Game", -300, -50);
	}
	else if (selectState == false)
	{
		textWriter->drawText("   Start Game", -300, -80);
		textWriter->drawText("> Exit Game", -300, -50);
	}
}

void Game::drawGame()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		drawMainMenu();
	}
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setModelMatrix(glm::mat4(1.0f));
	tigl::shader->setViewMatrix(view);

	screen->draw();

	for (auto& o : objects)
		o->draw();

	for (auto& i : ingredients)
		i->draw();

	buildingBurger->draw();
	buildingRecipeBurger.draw();

	textWriter->setScale(5.0f);
	std::string time = getTimeLeft();
	textWriter->drawText( time , 180, 230);

	textWriter->setScale(5.0f);
	std::string score2 = std::to_string(score);
	textWriter->drawText(score2, 100, 150);

	if (gameOver) 
	{
		textWriter->setScale(15.0f);
		textWriter->drawText("GAME OVER", -95, 0);
		textWriter->setScale(8.0f);
		textWriter->drawText("PRESS ESC TO RETURN TO MENU", -270, 50);
		tigl::shader->setLightAmbient(0, glm::vec3(0.8f, 0.0f, 0.1f)); //sets light to the color red
	}

	if (buildingBurger->isfinnished()) {
		glm::vec3 rotation = buildingRecipeBurger.getRotation();
		buildingBurger->clearBurger();
		buildingRecipe->generateRecipe(8);
		buildingRecipeBurger = buildingRecipe->convertToBurger();
		buildingRecipeBurger.setPosition(glm::vec3(12, -1.5, -15));
		buildingRecipeBurger.distanceIngredients = 3;
		buildingRecipeBurger.rebuildBurgerYPos();
		buildingRecipeBurger.setRotation(rotation);
		buildingBurger->addComponent(new BunHeelModelComponent());
		buildingBurgerIndex = 1;
		setNewTotalTime(20);
	}
}

std::string Game::getTimeLeft()
{
	long timeLeft = totalTime - stopwatch->getElapsedTime();

	int minutes = timeLeft / 60;
	long seconds = timeLeft % 60;
	std::string zero;
	seconds < 10 ? zero = "0" : zero = "";

	if (timeLeft <= 0)
	{
		gameOver = true;
		return "00:00";
	}

	return "0" + std::to_string(minutes) + ":" + zero + std::to_string(seconds);
}

//Adds 20 seconds to time left and resets timer
void Game::setNewTotalTime(int time)
{
	long timeLeft = totalTime - stopwatch->getElapsedTime();
	
	stopwatch->start();
	timeLeft + time > 120 ? totalTime = 120 : totalTime = timeLeft + time;	
}

/**
 * Set objects
 */
void Game::setScreen()
{
	screen = new GameObject();
	screen->addComponent(new ScreenMOdelComponent());
}

/**
 * setIngredients & other ingredient functions
 */
void Game::setIngredients()
{
	double x = -12.0;
	double y = 8.0;
	double z = -15.0; 
	double offset = 0;

	int amountInRow = 4;

	std::vector<BurgerIngredient*> baseList = Recipe::getBaseIngredientList(true);

	double distance = std::abs((x * 2) / (amountInRow - 1) * 0.9);

	for (int i = 0; i < baseList.size(); i++)
	{

		double newX = x + (distance * (i % amountInRow)) + offset;
		double newY = y - (3 * std::floor(i / amountInRow));

		GameObject* ingredient = new GameObject();
		ingredient->addComponent(baseList[i]);
		ingredient->position = glm::vec3(newX, newY, z);
		ingredient->rotation.y = 3 * .25f;
		ingredient->scale = glm::vec3(1.5, 1.5, 1.5);

		ingredients.push_back(ingredient);
	}

	GameObject* crown = new GameObject();
	crown->addComponent(new BunCrownModelComponent());
	crown->position = glm::vec3(x, y * -1, z);
	crown->rotation.y = 3 * .25f;

	buildingBurger = new Burger();
	buildingBurger->setPosition(glm::vec3(0, y * -1, z));

	GameObject* trash = new GameObject();
	trash->addComponent(new SimpleTrashBin());
	trash->position = glm::vec3(-x, y * -1, z);
	trash->scale = glm::vec3(1.5, 1.5, 1.5);
	trash->grabbable = false;

	buildingRecipeBurger.setPosition(glm::vec3(-x, 0 , z));
	buildingRecipeBurger.rebuildBurgerYPos();

	ingredients.push_back(crown);
	ingredients.push_back(trash);
}

/**
 * All functions based on hand, ingredient and burger management
 */
void Game::manageHandToIngredientPosition()
{

	Point pixelPosition = cam.GetCenter(75, 130);
	glm::vec2 position = pixelToOpenGL(glm::vec2(pixelPosition.x, pixelPosition.y));

	cursor->position.x = position.x;
	cursor->position.y = position.y;

	tigl::shader->setLightAmbient(0, glm::vec3(1.0f, 1.0f, 1.0f));

	bindIngredientToHand(position);
	bindIngredientToBurger(position);
}

glm::vec2 Game::pixelToOpenGL(glm::vec2 pixel)
{

	double maxX = 12.4, minX = -12.4, maxY = -10.2, minY = 10.2; // dimentions of our OpenGL world
	double factorX = camWidth / (maxX - minX);
	double factorY = camHeight / (maxY - minY);

	return glm::vec2((pixel.x / factorX) + minX, (pixel.y / factorY) + minY);
}

void Game::bindIngredientToHand(glm::vec2 p)
{
	for (GameObject* o : ingredients)
		if (!cursor->attached || !o->grabbable) // filters out grabbable ingredients if attached.
			if (inDistanceOf(p, o->position, radius))
				if (o->grabbable)
					cursor->replaceComponent(o->getComponents().front(), true);
				else
					cursor->replaceComponent(new CubeModelComponent(0.1), false);
}

void Game::bindIngredientToBurger(glm::vec2 p)
{
	if (cursor->attached && inDistanceOf(p, buildingBurger->getPosition(), radius))
	{
		BurgerIngredient* ingredient = cursor->getComponent<BurgerIngredient>();
		
		/*std::cout << "BURGER DEBUG : RECIPE INGREDIENT" << buildingRecipeBurger.getIngredientByIndex(buildingBurgerIndex)->getName() << "\n";
		std::cout << "BURGER DEBUG : USER INGREDIENT" << ingredient->getName() << "\n";
		std::cout << "BURGER DEBUG : BURGER INDEX" << buildingBurgerIndex << "\n";*/

		SauceBottle* bottle = dynamic_cast<SauceBottle*>(ingredient);
		if (bottle) {
			ingredient = (new SauceModelComponent(bottle->getSauseType()));
		}
		//Compare recipe ingredient to user ingredient
		if (buildingRecipeBurger.getIngredientByIndex(buildingBurgerIndex)->getName() == ingredient->getName()) 
		{
			//std::cout << "Ingredient correct, adding to burger" << "\n";
			buildingBurger->addComponent(ingredient);
			cursor->replaceComponent(new CubeModelComponent(0.1), false);
			buildingBurgerIndex++;
			score+=15;
			setNewTotalTime(5);
		}
		else
		{
			//std::cout << "Ingredient incorrect" << "\n";
			tigl::shader->setLightAmbient(0, glm::vec3(0.8f, 0.0f, 0.1f)); //sets light to the color red
			score--;
		}
	}
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

bool Game::inDistanceOf(glm::vec2 position, glm::vec3 object, double radius)
{

	return (
		pow((position.x - object.x), 2) +
		pow((position.y - object.y), 2) <
		pow(radius, 2)
	);
}

void Game::endGame()
{
	gameState = false;
	drawMainMenu();
}