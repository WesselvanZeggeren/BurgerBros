#include "SauceModelComponent.h"


SauceModelComponent::SauceModelComponent() {
    SauceModelComponent(0);
}

SauceModelComponent::SauceModelComponent(int type)
{
    setSauseType(type);
    model.drawRectangle(0.4, 0.1, 0.4);
    model.moveBrush(0.2, 0, 0);
    model.drawRectangle(0.1, 0.1, 0.2);
    model.moveBrush(0.2, 0, 0.1);
    model.drawRectangle(0.3, 0.1, 0.1);
    model.moveBrush(-0.2, 0, 0);
    model.drawRectangle(0.1, 0.1, 0.2);
    model.moveBrush(-0.2, 0, -0.1);
    model.drawRectangle(0.3, 0.1, 0.1);
}

SauceModelComponent::~SauceModelComponent()
{
}

void SauceModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double SauceModelComponent::getIngredientHeight()
{
    return 0.1;
}

void SauceModelComponent::setSauseType(int type)
{
    Color ketchup = { 204.0,0,0, 1.0 };
    Color mustard = { 255, 219, 88, 1.0 };
    Color mayo = { 255,255,238 ,1 };

    model.moveBrush(0, 0.05, 0);

    switch (type) {
    case 0:
        model.setColor(ketchup);
        break;
    case 1:
        model.setColor(mustard);
        break;
    case 2:
        model.setColor(mayo);
        break;
    }
}
