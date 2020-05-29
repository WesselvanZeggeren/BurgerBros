#include "LettuceModelComponent.h"

const std::string ingredientName;

LettuceModelComponent::LettuceModelComponent()
{
	ingredientName = "Lettuce";
}

LettuceModelComponent::~LettuceModelComponent()
{
}

void LettuceModelComponent::draw()
{
}

double LettuceModelComponent::getIngredientHeight()
{
	return 0.0;
}

double LettuceModelComponent::getIngredientRecipeHeight()
{
	return 0.5;
}

std::string LettuceModelComponent::getIngredientName()
{
	return ingredientName;
}
