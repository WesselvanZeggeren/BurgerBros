#include "ShapeMaker.h"

ModelMaker::ModelMaker()
{
}

ModelMaker::~ModelMaker()
{
}

void ModelMaker::drawRectangle(double x, double y, double z)
{
	//normal shading
	/*
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, -1)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, 0, 1)));

	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, 0, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, 0, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, 0, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, 0, 0)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, -1, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, -1, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, -1, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, -1, 0)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, 0, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, 0, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, 0, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, 0, 0)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, 1, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, 1, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(0, 1, 0)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(0, 1, 0)));
	*/


	//smooth shading
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, -1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, 1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, 1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, -1, -1)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, -1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, 1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, 1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, -1, 1)));

	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, -1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, 1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, 1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, -1, 1)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, -1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, -1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, -1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, -1, -1)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, -1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, 1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, 1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, -(y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, -1, 1)));

	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(-1, 1, -1)));
	vertacies.push_back(Vertex::PCN(glm::vec3(-(x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(-1, 1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, (z / 2) + brushPos.z), activeColor, glm::vec3(1, 1, 1)));
	vertacies.push_back(Vertex::PCN(glm::vec3((x / 2) + brushPos.x, (y / 2) + brushPos.y, -(z / 2) + brushPos.z), activeColor, glm::vec3(1, 1, -1)));

}

void ModelMaker::setColor(Color activeColor)
{
	this->activeColor = activeColor.getVec4();
}

glm::vec4 ModelMaker::getColor()
{
	return this->activeColor;
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
