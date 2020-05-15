#include "UnionModelComponent.h"

UnionModelComponent::UnionModelComponent()
{
}

UnionModelComponent::~UnionModelComponent()
{
}

void UnionModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double UnionModelComponent::getIngredientHeight()
{
	return 0.0;
}
