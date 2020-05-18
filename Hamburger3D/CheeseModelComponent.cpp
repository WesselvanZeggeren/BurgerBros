#include "CheeseModelComponent.h"

CheeseModelComponent::CheeseModelComponent(int type)
{
    Color chedar = { 255.0, 166.0, 0.0, 1.0 };
    Color emmet = { 255.0, 239.0, 193.0, 1.0 };
    Color mat_chedar = { 247.0 ,213.0 ,143.0, 1.0 };
    model.moveBrush(0, 0.05, 0);
    switch (type) {
    case 0:
        model.setColor(chedar);
        break;
    case 1:
        model.setColor(emmet);
        break;
    case 2:
        model.setColor(mat_chedar);
        break;
    }

    model.drawRectangle(2.1, 0.1, 2.1);
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
