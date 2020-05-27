#include "CucumberModelComponent.h"



CucumberModelComponent::~CucumberModelComponent()
{
}

CucumberModelComponent::CucumberModelComponent()
{
}

void CucumberModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double CucumberModelComponent::getIngredientHeight()
{
	return 0.0;
}
