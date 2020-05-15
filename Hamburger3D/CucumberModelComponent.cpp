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
