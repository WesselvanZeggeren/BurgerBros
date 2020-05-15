#ifndef COLOR_H
#define COLOR_H

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

namespace bcl 
{
	Color bread = { 198.0, 137.0, 88.0, 1.0 };

	Color chedar = { 255.0, 166.0, 0.0, 1.0 };
	Color emmet = { 255.0, 239.0, 193.0, 1.0 };
	Color mat_chedar = { 247.0 ,213.0 ,143.0, 1.0 };

	Color patty = { 163.0,56.0,21.0, 1.0 };

	Color tomato_red = { 232.0,24.0,2.0, 1.0 };
	Color tomato_red_light = { 253, 60, 39, 1.0 };

	Color ketchup = { 204.0,0,0, 1.0 };
	Color mustard = { 255, 219, 88, 1.0 };
	Color mayo = { 255,255,238 ,1 };

	Color egg_white = { 255, 245, 195 , 1 };
	Color egg_yelow = { 255,220,81 , 1 };

	Color bacon_dark = { 157,59,33 , 1 };
	Color bacon_light = { 137,0,0 , 1 };


}
#endif // COLOR_H

