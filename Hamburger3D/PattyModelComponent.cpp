#include "PattyModelComponent.h"

PattyModelComponent::PattyModelComponent()
{
    model = glm::translate(model, glm::vec3(0, -1.5, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(2.3, 0.5, 1.8, patty.getVec4());
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(2.3, 0.5, 1.8, patty.getVec4());
}

PattyModelComponent::~PattyModelComponent()
{
}

void PattyModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
