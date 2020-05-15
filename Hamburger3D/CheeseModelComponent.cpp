#include "CheeseModelComponent.h"

CheeseModelComponent::CheeseModelComponent(int type)
{
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0, -1, 0)));
    if (type == 0) {
        shape::drawRect(2.1, 0.1, 2.1, chedar.getVec4());
    }
    else if (type == 1)
    {
        shape::drawRect(2.1, 0.1, 2.1, emmet.getVec4());
    }
    else if (type == 2)
    {
        model.setColor(bcl::mat_chedar);
    }
    model.moveBrush(0, 0.05, 0);
    model.drawRectangle(2.1, 0.1, 2.1);
}

CheeseModelComponent::~CheeseModelComponent()
{
}

void CheeseModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
