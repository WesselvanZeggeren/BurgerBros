#include "PattyModelComponent.h"


PattyModelComponent::PattyModelComponent()
{
    this->name = "Patty";

    Color patty = { 163.0,56.0,21.0, 1.0 };
    model.setColor(patty);
    model.moveBrush(0, 0.25, 0);
    model.drawRectangle(2.3, 0.5, 1.8);
    model.drawRectangle(1.8, 0.5, 2.3);
}

PattyModelComponent::~PattyModelComponent()
{
}

void PattyModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double PattyModelComponent::getIngredientHeight()
{
    return 0.5;
}

std::string PattyModelComponent::getName()
{
	return this->name;
}
