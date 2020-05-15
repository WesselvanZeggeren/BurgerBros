#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
using tigl::Vertex;

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

using namespace cv;
using namespace std;

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
    double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
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

    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PT(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
    tigl::addVertex(Vertex::PT(glm::vec3(1, -1, 0), glm::vec2(1, 0)));
    tigl::addVertex(Vertex::PT(glm::vec3(1, 1, 0), glm::vec2(1, -1)));
    tigl::addVertex(Vertex::PT(glm::vec3(-1, 1, 0), glm::vec2(0, -1)));
    tigl::end();

    glDisable(GL_TEXTURE_2D);

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