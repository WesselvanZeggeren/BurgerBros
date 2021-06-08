#include "TomatoModelComponent.h"

TomatoModelComponent::TomatoModelComponent()
{
    this->name = "Tomato";

    Color tomato_red = { 232.0,24.0,2.0, 1.0 };
    Color tomato_red_light = { 253, 60, 39, 1.0 };

    model.setColor(tomato_red);
    model.moveBrush(0, 0.08, 0);
    model.drawRectangle(1.4, 0.15, 1.0);
    model.drawRectangle(1.0, 0.15, 1.4);
    model.setColor(tomato_red_light);
    model.drawRectangle(1, 0.16, 1);

}

TomatoModelComponent::~TomatoModelComponent()
{
}

void TomatoModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double TomatoModelComponent::getIngredientHeight()
{
    return 0.16;
}

std::string TomatoModelComponent::getName()
{
    return this->name;
}
