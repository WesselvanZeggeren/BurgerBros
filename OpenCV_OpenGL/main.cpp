// ************************************************************************************************************************************************
// ********************************************** Camera ******************************************************************************************
// ************************************************************************************************************************************************

// Dit programma leest continue een camera beeld in en toont deze op het scherm
// Bij sommige camera's is het beeld gespiegeld. Dit kan worden opgelost 
// met de flip-functie van OpenCV.
// 
// Jan Oostindie, dd 22-2-2015

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
using tigl::Vertex;


#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

using namespace cv;
using namespace std;

GLFWwindow* window;

void init();
void update();
void draw();
void drawCube();
void key_callback(GLFWwindow*, int, int, int, int);

int cubeMidXPos = 0;
int cubeMidZPos = 0;

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

    glfwSetKeyCallback(window, key_callback);
    glEnable(GL_DEPTH_TEST);

}

float angle = 0.0f;

void update()
{
    angle += 0.01f;
}

void draw()
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    glViewport(0, 0, width, height);

    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 projection = glm::perspective(45.0f, (width / (float)height), 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(view);

    tigl::shader->enableColor(true);

    glm::mat4 modelLeft = glm::mat4(1.0f);
    modelLeft = glm::translate(modelLeft, glm::vec3(-5, 0, 0));
    modelLeft = glm::rotate(modelLeft, angle, glm::vec3(1, 0, 0));
    tigl::shader->setModelMatrix(modelLeft);
    drawCube();


    glm::mat4 modelMid = glm::mat4(1.0f);
    modelMid = glm::translate(modelMid, glm::vec3(cubeMidXPos, 0, cubeMidZPos));
    modelMid = glm::rotate(modelMid, angle, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(modelMid);
    drawCube();

    glm::mat4 modelRight = glm::mat4(1.0f);
    modelRight = glm::translate(modelRight, glm::vec3(5, 0, 0));
    modelRight = glm::rotate(modelRight, angle, glm::vec3(0, 0, 1));
    tigl::shader->setModelMatrix(modelRight);
    drawCube();

    glm::mat4 modelBack = glm::mat4(1.0f);
    modelBack = glm::translate(modelBack, glm::vec3(0, 0, -5));
    tigl::shader->setModelMatrix(modelBack);
    drawCube();
}

void drawCube()
{
    tigl::begin(GL_QUADS);
    //front
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 0), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 0), glm::vec4(0, 0, 1, 1)));

    //left
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, -1), glm::vec4(0, 0, 1, 1)));

    //back
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, -1), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(0, 0, 1, 1)));

    //right
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 0), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 0), glm::vec4(0, 0, 1, 1)));

    //top
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 0), glm::vec4(0, 0, 1, 1)));

    //bottom
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, 0), glm::vec4(-1, 0, 0, -1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 0, -1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, -1), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 0, 0), glm::vec4(0, 0, 1, 1)));
    tigl::end();

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_UP) {
        printf("up");
        cubeMidZPos += 0.5;
        std::cout << cubeMidZPos << '\n';
    }
    if (key == GLFW_KEY_DOWN) {
        printf("down");
        cubeMidZPos -= 0.5;
        std::cout << cubeMidZPos << '\n';
    }
    if (key == GLFW_KEY_RIGHT) {
        printf("right");
        cubeMidXPos += 0.5;
        std::cout << cubeMidXPos << '\n';
    }
    if (key == GLFW_KEY_LEFT) {
        printf("left" + cubeMidXPos);
        cubeMidXPos += 0.5;
        std::cout << cubeMidXPos << '\n';
    }

}