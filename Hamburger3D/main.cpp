#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "basicShapeDrawer.h"
#include "BurgerDrawer.h"
#include <glm/gtc/matrix_transform.hpp>
using tigl::Vertex;

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

float angle = 0.0f;
float x = 0, y = 0, z = 0;
bool doWireFrame = false;
int wCooldown = 0;

void init()
{
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
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
    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void update()
{
    angle += 0.005;
    wCooldown--;
}

void draw()
{
    int height, width;
    glfwGetWindowSize(window, &width, &height);

    glViewport(0, 0, width, height);

    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(x, y, z));
    model = glm::rotate(model, angle, glm::vec3(0, 1, 0));

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 5, 10), glm::vec3(x, y, z), glm::vec3(0, 1, 0));

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(view);

    tigl::shader->enableColor(true);


    
    bdm::burgerBunCrown(model);
    bdm::burgerBunHeel(model);
    bdm::cheese(model, 0);
    bdm::burgerPatty(model);
    bdm::tomato(model);

    bdm::souce(model, 2);
}