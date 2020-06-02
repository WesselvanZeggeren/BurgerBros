#include "PickleModelComponent.h"

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
