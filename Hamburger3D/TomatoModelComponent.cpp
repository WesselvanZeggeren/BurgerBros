#include "TomatoModelComponent.h"

TomatoModelComponent::TomatoModelComponent()
{
    model = glm::translate(model, glm::vec3(0, -0.6, 0));
    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(1.4, 0.15, 1.0, tomato_red.getVec4());
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(1.4, 0.15, 1.0, tomato_red.getVec4());
    shape::drawRect(1, 0.16, 1, tomato_red_light.getVec4());
}

TomatoModelComponent::~TomatoModelComponent()
{
}

void TomatoModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
