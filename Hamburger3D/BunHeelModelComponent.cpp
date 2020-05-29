#include "BunHeelModelComponent.h"

const std::string ingredientName;

BunHeelModelComponent::BunHeelModelComponent()
{
	Color bread = { 198.0, 137.0, 88.0, 1.0 };

	ingredientName = "Bun heel";

	model.moveBrush(0, 0.25, 0);
	model.setColor(bread);
	model.drawRectangle(2, 0.5, 2);

}

BunHeelModelComponent::~BunHeelModelComponent()
{
}

void BunHeelModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

double BunHeelModelComponent::getIngredientHeight()
{
	return 0.5;
}

double BunHeelModelComponent::getIngredientRecipeHeight()
{
	return 1.0;
}

std::string BunHeelModelComponent::getIngredientName()
{
	return ingredientName;
}
