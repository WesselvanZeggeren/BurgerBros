#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
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

void init()
{

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE)
                glfwSetWindowShouldClose(window, true);
        });

    glEnable(GL_DEPTH_TEST);
}

float angle = 0.0f;

void update()
{

    angle += 0.0005f;
}

void draw()
{

    int width, heigth;
    glfwGetWindowSize(window, &width, &heigth);

    glViewport(0, 0, width, heigth);
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 projection = glm::perspective(45.0f, (width / (float)heigth), .1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 3.5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(view);
    tigl::shader->enableColor(true);

    for (int x = -1; x <= 1; x += 1) {
        for (int z = -10; z <= 0; z += 1) {

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(x * 3, 0, z * 3));

            if (x == -1 && z == 0) model = glm::rotate(model, angle, glm::vec3(1, 0, 0));
            if (x == 0 && z == 0) model = glm::rotate(model, angle, glm::vec3(0, 1, 0));
            if (x == 1 && z == 0) model = glm::rotate(model, angle, glm::vec3(0, 0, 1));

            tigl::shader->setModelMatrix(model);

            tigl::begin(GL_QUADS);

            tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(1, 0, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(1, 0, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), glm::vec4(1, 0, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), glm::vec4(1, 0, 0, 1)));

            tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), glm::vec4(0, 1, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 1, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(0, 1, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(0, 1, 0, 1)));

            tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), glm::vec4(0, 0, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), glm::vec4(0, 0, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 0, 1, 1)));

            tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(1, 0, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(1, 0, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(1, 0, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), glm::vec4(1, 0, 1, 1)));

            tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), glm::vec4(1, 1, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), glm::vec4(1, 1, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), glm::vec4(1, 1, 0, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(1, 1, 0, 1)));

            tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(0, 1, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 1, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 1, 1, 1)));
            tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(0, 1, 1, 1)));

            tigl::end();
        }
    }
}