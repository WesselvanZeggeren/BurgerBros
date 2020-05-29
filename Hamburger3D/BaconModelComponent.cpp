#include "BaconModelComponent.h"

const std::string ingredientName;

BaconModelComponent::BaconModelComponent()
{
    Color bacon_dark = { 157,59,33 , 1 };
    Color bacon_light = { 137,0,0 , 1 };

    ingredientName = "Bacon";

    model.moveBrush(0, 0.025, 0.1);
    //model.rotate(model, 45.0f, glm::vec3(0, 1, 0));
    for (int i = 0; i < 4; i++) {
        model.moveBrush(0, 0, 0.125);
        if (i % 2 == 1) {
            model.setColor(bacon_dark);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
        else {
            model.setColor(bacon_light);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
    }

    model.moveBrush(0, 0, -1.2);

    for (int i = 0; i < 4; i++) {
        model.moveBrush(0, 0, 0.125);
        if (i % 2 == 1) {
            model.setColor(bacon_dark);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
        else
        {
            model.setColor(bacon_light);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
    }
   
}

BaconModelComponent::~BaconModelComponent()
{
}

void BaconModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double BaconModelComponent::getIngredientHeight()
{
    return 0.05;
}

double BaconModelComponent::getIngredientRecipeHeight()
{
    return 0.5;
}

std::string BaconModelComponent::getIngredientName()
{
    return ingredientName;
}


