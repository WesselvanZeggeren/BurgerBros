#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>

namespace shape {
	void drawTriangle();
	void drawSquare();
	void drawDiamond();
	void drawCircle(double x, double y, double z, glm::vec4 color, float smoothnes);
	void drawRect(double x, double y, double z, glm::vec4 color);
	void drawTube(double x, double y, double z, glm::vec4 color, float smoothnes);
	void drawCilinder(double x, double y, double z, glm::vec4 color, float smoothnes);
}

namespace transform {

}


