#include "SouceModelComponent.h"

SouceModelComponent::SouceModelComponent()
{
    model = glm::translate(model, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    Color souceColor = { 0,0,0,0 };
    if (type == 0) {
        souceColor = ketchup;
    }
    else if (type == 1)
    {
        souceColor = mustard;
    }
    else if (type == 2) {
        souceColor = mayo;
    }

    shape::drawRect(0.4, 0.1, 0.4, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0.2, 0, 0)));
    shape::drawRect(0.1, 0.1, 0.2, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0.2, 0, 0.1)));
    shape::drawRect(0.3, 0.1, 0.1, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(-0.2, 0, 0)));
    shape::drawRect(0.1, 0.1, 0.2, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(-0.2, 0, -0.1)));
    shape::drawRect(0.3, 0.1, 0.1, souceColor.getVec4());
}

SouceModelComponent::~SouceModelComponent()
{
}

void SouceModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
