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

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

GLFWwindow* window;

int main(void)
{
    return 0;
}