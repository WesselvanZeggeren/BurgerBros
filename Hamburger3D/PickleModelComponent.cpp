#include "PickleModelComponent.h"

const std::string ingredientName = "Pickle";

PickleModelComponent::PickleModelComponent()
{
}

PickleModelComponent::~PickleModelComponent()
{
}

void PickleModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double PickleModelComponent::getIngredientHeight()
{
	return 0.0;
}

std::string PickleModelComponent::getIngredientName()
{
	return ingredientName;
}
