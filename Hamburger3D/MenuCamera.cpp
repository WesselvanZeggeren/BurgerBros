#include "MenuCamera.h"
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

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

	if (x < 300) { glfwSetCursorPos(window, 300, y); x = 300; }
	if (x > 450) { glfwSetCursorPos(window, 450, y); x = 450; }


	static double lastX = x;
	static double lastY = y;

	rotation.x -= (float)(lastY - y) / 100.0f;
	rotation.y -= (float)(lastX - x) / 100.0f;

	lastX = x;
	lastY = y;

}