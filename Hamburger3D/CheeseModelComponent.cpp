#include "CheeseModelComponent.h"





CheeseModelComponent::CheeseModelComponent(int type)
{
    Color chedar = { 255.0, 166.0, 0.0, 1.0 };
    Color emmet = { 255.0, 239.0, 193.0, 1.0 };
    Color mat_chedar = { 247.0 ,213.0 ,143.0, 1.0 };
    /*
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
    */

}

CheeseModelComponent::~CheeseModelComponent()
{
}

void CheeseModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double CheeseModelComponent::getIngredientHeight()
{
    return 0.1;
}
