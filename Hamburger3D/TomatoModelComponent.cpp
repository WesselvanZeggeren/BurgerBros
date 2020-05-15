#include "TomatoModelComponent.h"

Color tomatoRedColor = { 232.0,24.0,2.0, 1.0 };
Color tomatoRedLightColor = { 253, 60, 39, 1.0 };

TomatoModelComponent::TomatoModelComponent()
{
    model.setColor(tomatoRedColor);
    model.moveBrush(0, -0.6, 0);
    //model.rotate(model, glm::radians(45.0f), glm::vec3(0, 1, 0));
    model.drawRectangle(1.4, 0.15, 1.0);
    //model.rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0);
    model.drawRectangle(1.4, 0.15, 1.0);
    model.setColor(tomatoRedLightColor);
    model.drawRectangle(1, 0.16, 1);

    //model = glm::translate(model, glm::vec3(0, -0.6, 0));
    //model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0, 1, 0));
    //tigl::shader->setModelMatrix(model);
    //shape::drawRect(1.4, 0.15, 1.0, tomato_red.getVec4());
    //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    //tigl::shader->setModelMatrix(model);
    //shape::drawRect(1.4, 0.15, 1.0, tomato_red.getVec4());
    //shape::drawRect(1, 0.16, 1, tomato_red_light.getVec4());
}

TomatoModelComponent::~TomatoModelComponent()
{
}

void TomatoModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
