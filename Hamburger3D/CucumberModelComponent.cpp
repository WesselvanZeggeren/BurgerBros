#include "CucumberModelComponent.h"


#include "CucumberModelComponent.h"

CucumberModelComponent::CucumberModelComponent()
{
    Color cucumber_light = { 49, 199, 4, 1 };
    Color cucumber_dark = { 37, 156, 3, 1 };

    model.setColor(cucumber_dark);
    model.moveBrush(0, 0.08, 0);
    model.drawRectangle(1.4, 0.15, 1.0);
    model.drawRectangle(1.0, 0.15, 1.4);
    model.setColor(cucumber_dark);
    model.drawRectangle(1, 0.16, 1);
}

CucumberModelComponent::~CucumberModelComponent()
{
}

void CucumberModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double CucumberModelComponent::getIngredientHeight()
{
	return 0.16;
}
