#include "EggModelComponent.h"

EggModelComponent::EggModelComponent()
{
    model = glm::translate(model, glm::vec3(0, -0.8, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(2.3, 0.2, 1.8, egg_white.getVec4());
    shape::drawRect(2.4, 0.1, 1.6, egg_white.getVec4());
    shape::drawRect(2.1, 0.1, 1.9, egg_white.getVec4());
    tigl::shader->setModelMatrix(glm::rotate(glm::translate(model, glm::vec3(0.3, 0.2, 0.3)), glm::radians(25.0f), glm::vec3(0, 1, 0)));
    shape::drawRect(0.8, 0.2, 0.8, egg_yelow.getVec4());
}

EggModelComponent::~EggModelComponent()
{
}

void EggModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
