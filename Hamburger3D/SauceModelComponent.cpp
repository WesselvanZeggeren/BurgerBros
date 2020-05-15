#include "SouceModelComponent.h"


Color ketchup = { 204.0,0,0, 1.0 };
Color mustard = { 255, 219, 88, 1.0 };
Color mayo = { 255,255,238 ,1 };

SouceModelComponent::SouceModelComponent(int type)
{
    model.moveBrush(0, 1, 0);

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

    model.drawRectangle(0.4, 0.1, 0.4);
    model.moveBrush(0.2, 0, 0);
    model.drawRectangle(0.1, 0.1, 0.2);
    model.moveBrush(0.2, 0, 0.1);
    model.drawRectangle(0.3, 0.1, 0.1);
    model.moveBrush(-0.2, 0, 0);
    model.drawRectangle(0.1, 0.1, 0.2);
    model.moveBrush(-0.2, 0, -0.1);
    model.drawRectangle(0.3, 0.1, 0.1);

    /**
    model = glm::translate(model, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    Color sauceColor = { 0,0,0,0 };
    if (type == 0) {
        sauceColor = ketchup;
    }
    else if (type == 1)
    {
        sauceColor = mustard;
    }
    else if (type == 2)
    {
        sauceColor = mayo;
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
    */
}

SouceModelComponent::~SouceModelComponent()
{
}

void SouceModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
