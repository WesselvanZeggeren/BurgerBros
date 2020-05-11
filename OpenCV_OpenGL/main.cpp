// ************************************************************************************************************************************************
// ********************************************** BurgerBros **************************************************************************************
// ************************************************************************************************************************************************

//OpenGl includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
using tigl::Vertex;


#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

	//OpenCV includes
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
	Camera cam;
	cam.SetUpCamera(0);
	return 1;
}