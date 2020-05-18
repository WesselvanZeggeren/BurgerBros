#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
using tigl::Vertex;

#include "GameObject.h"
#include "Burger.h"
#include "SauceBottle.h"

#include "CubeModelComponent.h"
#include "SpinComponent.h"
#include "BunCrownModelComponent.h"

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

GLFWwindow* window;

void init();
void update();
void draw();

int main(void)
{
	if (!glfwInit())
		throw "Could not initialize glwf";
	window = glfwCreateWindow(1400, 800, "Hello World", NULL, NULL);
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
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();


	return 0;
}


std::list<GameObject*> objects;
double lastFrameTime = 0;
Burger burger;

float x = 0, y = 0, z = 0;
bool doWireFrame = false;
int wCooldown = 0;

void init()
{
	glEnable(GL_DEPTH_TEST);

    GameObject* bottle = new GameObject();
    bottle->position = glm::vec3(0, 0, 0);
    bottle->rotation.y = 3 * .25f;
    bottle->addComponent(new SauceBottle(2));
    //bottle->addComponent(new CubeModelComponent(1));
    bottle->addComponent(new SpinComponent(1));
    objects.push_back(bottle);


    burger = Burger();
    burger.addIngriedient(new SauceModelComponent(2));
    burger.addIngriedient(new PattyModelComponent());
    burger.addIngriedient(new CucumberModelComponent());
    burger.addIngriedient(new CheeseModelComponent(0));
    burger.addIngriedient(new LettuceModelComponent());
    burger.addIngriedient(new TomatoModelComponent());
    burger.addIngriedient(new EggModelComponent());
    burger.addIngriedient(new BaconModelComponent());
    burger.addIngriedient(new BunCrownModelComponent());
    

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, true);
        if (key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, true);
        if (key == GLFW_KEY_LEFT) {
            x -= 0.1;
        }
        if (key == GLFW_KEY_RIGHT) {
            x += 0.1;
        }
        if (key == GLFW_KEY_UP) {
            y += 0.1;
        }
        if (key == GLFW_KEY_DOWN) {
            y -= 0.1;
        }
        if (key == GLFW_KEY_W && wCooldown <= 0) {
            if (!doWireFrame) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                doWireFrame = true;
            }
            else
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                doWireFrame = false;
            }
            wCooldown = 500;
        }

	});
}


void update()
{
	double currentFrameTime = glfwGetTime();
	double deltaTime = currentFrameTime - lastFrameTime;
	lastFrameTime = currentFrameTime;

	for (auto& o : objects)
		o->update(deltaTime);

    burger.update(deltaTime);
    wCooldown--;

}

void draw()
{
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), viewport[2] / (float)viewport[3], 0.01f, 1000.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 1, 10), glm::vec3(x, y, z), glm::vec3(0, 1, 0));

	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setModelMatrix(glm::mat4(1.0f));
    tigl::shader->setViewMatrix(view);

	tigl::shader->enableColor(true);
	for (auto& o : objects)
		o->draw();

    //burger.draw();
}