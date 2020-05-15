#include "ShapeMaker.h"

ShapeMaker::ShapeMaker()
{
}

ShapeMaker::~ShapeMaker()
{
}

void ShapeMaker::drawRectangle(double x, double y, double z)
{

	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));

	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));

	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));

	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));

	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));

	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor));
	vertacies.push_back(Vertex::PC(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor));
}

void ShapeMaker::setColor(Color activeColor)
{
	this->activeColor = activeColor.getVec4();
}

void ShapeMaker::moveBrush(double x, double y, double z)
{
	this->brushPos = glm::vec3(brushPos.x + x, brushPos.y + y, brushPos.z + z);
}

void ShapeMaker::clearPosition()
{
	this->brushPos = glm::vec3(0, 0, 0);
}

void ShapeMaker::clearShapes()
{
	this->vertacies.clear();
}

void ShapeMaker::clearColor()
{
	this->activeColor = Color(255, 255, 255, 1).getVec4();
}

std::vector<Vertex> ShapeMaker::getVertacies()
{
	return this->vertacies;
}
