#include "FpCamera.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

using namespace std;

FpCam::FpCam(GLFWwindow* window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	if (glfwRawMouseMotionSupported())
		glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
}


glm::mat4 FpCam::getMatrix()
{
	glm::mat4 ret(1.0f);
	ret = glm::rotate(ret, rotation.x, glm::vec3(1, 0, 0));
	ret = glm::rotate(ret, rotation.y, glm::vec3(0, 1, 0));
	ret = glm::translate(ret, position);
	return ret;
}

void FpCam::update(GLFWwindow* window)
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);

	cout << x << y << "\n";
	if (x < 290) { glfwSetCursorPos(window, 290.0, y); x = 290; }
	if (x > 460) { glfwSetCursorPos(window, 460.0, y); x = 460; }

	static double lastX = x;
	static double lastY = y;

	rotation.x -= (float)(lastY - y) / 100.0f;
	rotation.y -= (float)(lastX - x) / 100.0f;

	lastX = x;
	lastY = y;

}