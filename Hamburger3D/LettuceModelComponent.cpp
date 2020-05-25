#include "LettuceModelComponent.h"

const std::string ingredientName = "Lettuce";

LettuceModelComponent::LettuceModelComponent()
{
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

std::string LettuceModelComponent::getIngredientName()
{
	return ingredientName;
}
