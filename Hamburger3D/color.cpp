#include "color.h"

Color::Color(double r, double g, double b)
{
	this->r = r / 255;
	this->g = g / 255;
	this->b = b / 255;
	this->s = 0.5;
}

Color::Color(double r, double g, double b, double s)
{
	this->r = r / 255.0;
	this->g = g / 255.0;
	this->b = b / 255.0;
	this->s = s;
}

glm::vec4 Color::getVec4()
{
	return glm::vec4(this->r, this->g, this->b, this->s);
}