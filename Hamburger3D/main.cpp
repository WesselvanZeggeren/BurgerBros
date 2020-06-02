#include "Game.h"
#include "Camera.h"

using namespace cv;
using namespace std;

Game game;
Camera camera;

int main(void)
{
	camera.SetUpCamera(0);

	game.startGame(camera.height, camera.width, camera);

	return 0;
}




void init()
{
    gameState = false;
	glEnable(GL_DEPTH_TEST);

    recipe.generateRecipe(10);
    burger = recipe.convertToBurger();
    burger.setPosition(glm::vec3(0, 10, -4));

    tigl::shader->enableColor(true);
    tigl::shader->enableTexture(true);
    tigl::shader->enableAlphaTest(true);
   
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{

		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, true);
        if (key == GLFW_KEY_SPACE) {
            gameState = true;
        }
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
        if (key == GLFW_KEY_P) {
            burger.startAnimation();
            gameState = true;
        }
        if (key == GLFW_KEY_R) {
            glm::vec3 rotation = burger.getRotation();
            recipe.generateRecipe(10);
            burger = recipe.convertToBurger();
            burger.setRotation(rotation);
            burger.setPosition(glm::vec3(0, 10, -4));
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
    
    camera = new FpCam(window);

    if (!cap.isOpened())
    {
        cout << "Cannot open the video cam" << endl;
    }
    else
    {
        getFrame();
    }
}


void drawGame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PCN(glm::vec3(0, 0, -8), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::addVertex(Vertex::PCN(glm::vec3(8, 0, 0), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::addVertex(Vertex::PCN(glm::vec3(0, 0, 8), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::addVertex(Vertex::PCN(glm::vec3(-8,0, 0), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::end();
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
    camera->update(window);

    BindCVMat2GLTexture(frame);
}

void drawMainMenu()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(camera->getMatrix());
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    //tigl::shader->enableLighting(true);
    tigl::shader->setLightCount(1);

    tigl::shader->setLightDirectional(0, false);
    tigl::shader->setLightPosition(0, glm::vec3(1, 2, 3));
    tigl::shader->setLightAmbient(0, glm::vec3(0.1f, 0.1f, 0.15f));
    tigl::shader->setLightDiffuse(0, glm::vec3(0.8f, 0.8f, 0.8f));
    tigl::shader->setLightSpecular(0, glm::vec3(0, 0, 0));
    tigl::shader->setShinyness(32.0f);

    double y = 0;
    int n = -1;

    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PT(glm::vec3(0, 0, -5), glm::vec2(1, 0)));
    tigl::addVertex(Vertex::PT(glm::vec3(0, 8, -5), glm::vec2(1, -1)));
    tigl::addVertex(Vertex::PT(glm::vec3(8, 8, 0), glm::vec2(0, -1)));
    tigl::addVertex(Vertex::PT(glm::vec3(8, 0, 0), glm::vec2(0, 0)));

    glDisable(GL_TEXTURE_2D);

    tigl::addVertex(Vertex::PCN(glm::vec3(0, y, -8), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::addVertex(Vertex::PCN(glm::vec3(8, y, 0), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::addVertex(Vertex::PCN(glm::vec3(0, y, 8), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));
    tigl::addVertex(Vertex::PCN(glm::vec3(-8, y, 0), glm::vec4(1, 1, 1, 1), glm::vec3(0, 1, 0)));

    tigl::addVertex(Vertex::PN(glm::vec3(0, 0, -5), glm::vec3(-1, 0, 0)));
    tigl::addVertex(Vertex::PN(glm::vec3(0, 8, -5), glm::vec3(-1, 0, 0)));
    tigl::addVertex(Vertex::PN(glm::vec3(-8, 8, 0), glm::vec3(-1, 0, 0)));
    tigl::addVertex(Vertex::PN(glm::vec3(-8, 0, 0), glm::vec3(-1, 0, 0)));

    tigl::end();


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