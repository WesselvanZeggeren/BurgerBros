#include "ShapeMaker.h"

ModelMaker::ModelMaker()
{
}

ModelMaker::~ModelMaker()
{
}

void ModelMaker::drawRectangle(double x, double y, double z)
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

void ModelMaker::setColor(Color activeColor)
{
	this->activeColor = activeColor.getVec4();
}

void ModelMaker::moveBrush(double x, double y, double z)
{
	this->brushPos = glm::vec3(brushPos.x + x, brushPos.y + y, brushPos.z + z);
}

void ModelMaker::clearPosition()
{
	this->brushPos = glm::vec3(0, 0, 0);
}

void ModelMaker::clearShapes()
{
	this->vertacies.clear();
}

void ModelMaker::clearColor()
{
	this->activeColor = Color(255, 255, 255, 1).getVec4();
}

std::vector<Vertex> ModelMaker::getVertacies()
{
	return this->vertacies;
}
