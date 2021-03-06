#pragma once
#include <glm/glm.hpp>

struct GLFWwindow;

class FpCam
{
public:
	FpCam(GLFWwindow*);

	glm::mat4 getMatrix();
	void update(GLFWwindow*);

private:
	glm::vec2 rotation = glm::vec2(0, 0);
	glm::vec3 position = glm::vec3(0, -3, -3);

};


