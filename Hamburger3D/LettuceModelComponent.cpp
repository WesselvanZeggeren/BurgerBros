#include "LettuceModelComponent.h"

LettuceModelComponent::LettuceModelComponent()
{
    Color letace_light = { 49, 199, 4, 1 };

    model.setColor(letace_light);
    model.moveBrush(0, 0.05, 0);
    model.drawRectangle(2.1, 0.1, 2.1);
}

LettuceModelComponent::~LettuceModelComponent()
{
}

void LettuceModelComponent::draw()
{
    tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double LettuceModelComponent::getIngredientHeight()
{
	return 0.1;
}

std::string LettuceModelComponent::getName()
{
	return "Lettuce";
}
