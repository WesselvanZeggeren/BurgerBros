#include "BunCorwnModelComponent.h"
#include "ShapeMaker.h"

BunCrownModelComponent::BunCrownModelComponent()
{
    model.setColor(bcl::bread);
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
    return 0.0;
}
