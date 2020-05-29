#include "CheeseModelComponent.h"

const std::string ingredientName;

CheeseModelComponent::CheeseModelComponent(int type)
{
    Color cheddar = { 255.0, 166.0, 0.0, 1.0 };
    Color emmet = { 255.0, 239.0, 193.0, 1.0 };
    Color matCheddar = { 247.0 ,213.0 ,143.0, 1.0 };

    model.moveBrush(0, 0.5, 0);

    switch (type) {

        case 0: model.setColor(cheddar); ingredientName = "Cheddar"; break;
        case 1: model.setColor(emmet); ingredientName = "Emmet"; break;
        case 2: model.setColor(matCheddar); ingredientName = "Mat cheddar"; break;
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

double CheeseModelComponent::getIngredientRecipeHeight()
{
    return 0.6;
}

std::string CheeseModelComponent::getIngredientName()
{
    return ingredientName;
}
