#include "OnionModelComponent.h"

const std::string ingredientName;

OnionModelComponent::OnionModelComponent()
{
	ingredientName = "Onion";
}

OnionModelComponent::~OnionModelComponent()
{
}

void OnionModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double OnionModelComponent::getIngredientHeight()
{
	return 0.0;
}

std::string OnionModelComponent::getIngredientName()
{
	return ingredientName;
}
