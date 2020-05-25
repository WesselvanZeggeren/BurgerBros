#include "CucumberModelComponent.h"

const std::string ingredientName;

CucumberModelComponent::~CucumberModelComponent()
{
	ingredientName = "Cucumber";
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

std::string CucumberModelComponent::getIngredientName()
{
	return ingredientName;
}
