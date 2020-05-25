#include "BunCrownModelComponent.h"

const std::string ingredientName;

BunCrownModelComponent::BunCrownModelComponent()
{
    Color bread = { 198.0, 137.0, 88.0, 1.0 };

    ingredientName = "Bun crown";

    model.setColor(bread);
    model.moveBrush(0, (0.75 / 2.0), 0);
    model.drawRectangle(2, 0.75, 2);
    model.moveBrush(0, 0.6, 0);
    model.drawRectangle(1.5, 0.5, 1.5);
}


BunCrownModelComponent::~BunCrownModelComponent()
{

}

void BunCrownModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double BunCrownModelComponent::getIngredientHeight()
{
    return 1.225;
}

std::string BunCrownModelComponent::getIngredientName()
{
    return ingredientName;
}


