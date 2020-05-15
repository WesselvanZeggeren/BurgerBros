#include "PattyModelComponent.h"

   Color patty = { 163.0,56.0,21.0, 1.0 };

PattyModelComponent::PattyModelComponent()
{
    model.setColor(pattyColor);
    model.moveBrush(0, (0.5 / 2.0), 0);
    model.drawRectangle(2.3, 0.5, 1.8);
    //model.rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    model.drawRectangle(2.3, 0.5, 1.8);

    //model = glm::translate(model, glm::vec3(0, -1.5, 0));
    //tigl::shader->setModelMatrix(model);
    //shape::drawRect(2.3, 0.5, 1.8, patty.getVec4());
    //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    //tigl::shader->setModelMatrix(model);
    //shape::drawRect(2.3, 0.5, 1.8, patty.getVec4());
}

PattyModelComponent::~PattyModelComponent()
{
}

void PattyModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
