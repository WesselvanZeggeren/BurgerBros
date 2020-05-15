#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm\fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Color
{
private:
	double r, g, b, s;
	Color();
public:
	~Color() = default;
	Color(double r, double g, double b);
	Color(double r, double g, double b, double s);

	glm::vec4 getVec4();

};






