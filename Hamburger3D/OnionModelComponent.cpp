#include "OnionModelComponent.h"

OnionModelComponent::OnionModelComponent()
{
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
