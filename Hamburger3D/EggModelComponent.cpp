#include "EggModelComponent.h"

EggModelComponent::EggModelComponent()
{
    Color egg_white = { 255, 245, 195 , 1 };
    Color egg_yelow = { 255, 220, 81 , 1 };
    
    model.setColor(egg_white);
    model.moveBrush(0, 0.1 , 0);
    model.drawRectangle(2.3, 0.2, 1.8);
    model.drawRectangle(2.4, 0.1, 1.6);
    model.drawRectangle(2.1, 0.1, 1.9);
    model.moveBrush(0.3, 0.1, 0.3);
    model.setColor(egg_yelow);
    model.drawRectangle(0.8, 0.2, 0.8);
}

EggModelComponent::~EggModelComponent()
{
}

void EggModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double EggModelComponent::getIngredientHeight()
{
    return 0.3;
}

std::string EggModelComponent::getName()
{
	return "Egg";
}
