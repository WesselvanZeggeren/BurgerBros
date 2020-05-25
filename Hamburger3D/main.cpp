#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>


#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"

#include "GameObject.h"
#include "Burger.h"
#include "Recipe.h"
//#include "PlayerComponent.h"
#include "SauceBottle.h"

#include "CubeModelComponent.h"
#include "SpinComponent.h"
#include "BunCrownModelComponent.h"

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

using tigl::Vertex;
using namespace cv;

GLFWwindow* window;
VideoCapture cap(0);
GLuint textureId = 0;
Mat image, frame;

void init();
void update();
void draw();

void BindCVMat2GLTexture(cv::Mat& image);
void getFrame();

int main(void)
{
    // Controle of de camera wordt herkend.
    if (!cap.isOpened())
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

    double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

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

Recipe recipe;
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
    bottle->addComponent(new SpinComponent(1));
    //objects.push_back(bottle);

    recipe.generateRecipe(10);
    burger = recipe.convertToBurger();
    /*
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
    */

    

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
        if (key == GLFW_KEY_R) {
            glm::vec3 rotation = burger.getRotation();
            recipe.generateRecipe(10);
            burger = recipe.convertToBurger();
            burger.setRotation(rotation);
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

    if (!cap.isOpened())
    {
        cout << "Cannot open the video cam" << endl;
    }
    else
    {
        getFrame();
    }
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
    getFrame();
}

void draw()
{
    BindCVMat2GLTexture(frame);

	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    tigl::shader->enableTexture(true);
    tigl::shader->enableColor(true);
    tigl::shader->enableAlphaTest(true);


	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 1000.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 5, 10), glm::vec3(x, y, z), glm::vec3(0, 1, 0));

	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setModelMatrix(glm::mat4(1.0f));
    tigl::shader->setViewMatrix(view);

    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PT(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
    tigl::addVertex(Vertex::PT(glm::vec3(1, -1, 0), glm::vec2(1, 0)));
    tigl::addVertex(Vertex::PT(glm::vec3(1, 1, 0), glm::vec2(1, -1)));
    tigl::addVertex(Vertex::PT(glm::vec3(-1, 1, 0), glm::vec2(0, -1)));
    tigl::end();

    glDisable(GL_TEXTURE_2D);

	
	/*	
	//temporary draw floor
	tigl::begin(GL_QUADS);
	tigl::addVertex(Vertex::PC(glm::vec3(-50, 0, -50), glm::vec4(1, 0, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(-50, 0, 50), glm::vec4(0, 1, 0, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(50, 0, 50), glm::vec4(0, 0, 1, 1)));
	tigl::addVertex(Vertex::PC(glm::vec3(50, 0, -50), glm::vec4(0, 0, 1, 1)));
	tigl::end();
	*/
	for (auto& o : objects)
		o->draw();

    burger.draw();
}


void BindCVMat2GLTexture(cv::Mat& image)
{
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,
        0,
        GL_RGB,
        image.cols,
        image.rows,
        0,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        image.data);
}

void getFrame()
{
    bool bSuccess = cap.read(image);

    if (!bSuccess)
    {
        cout << "Cannot read a frame from video stream" << endl;
    }
    else
    {
        flip(image, image, 3);
        cvtColor(image, frame, CV_BGR2RGB);
    }



}