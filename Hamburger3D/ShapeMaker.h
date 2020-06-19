#pragma once

 #include "tigl.h"
#include "color.h"

using tigl::Vertex;
using namespace std;


class ModelMaker {
private:
	std::vector<Vertex> vertacies;
	glm::vec3 brushPos;
	glm::vec4 activeColor;

public:
	ModelMaker();
	~ModelMaker();
	void drawRectangle(double x, double y, double z);
	void setColor(Color color);
	Color getColor();
	void moveBrush(double x, double y, double z);
	void clearPosition();
	void clearShapes();
	void clearColor();
	std::vector<Vertex> getVertacies();
			
};