#include "CheeseModelComponent.h"

CheeseModelComponent::CheeseModelComponent() {
    CheeseModelComponent(type);
}

CheeseModelComponent::CheeseModelComponent(int type)
{
    setCheeseType(type);

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

double CheeseModelComponent::getIngredientHeight()
{
    return 0.1;
}

void CheeseModelComponent::setCheeseType(int type)
{
    Color chedar = { 255.0, 166.0, 0.0, 1.0 };
    Color emmet = { 255.0, 239.0, 193.0, 1.0 };
    Color mat_chedar = { 247.0 ,213.0 ,143.0, 1.0 };

    switch (type) {

        case 0: model.setColor(chedar); this->name = "Cheddar"; break;
        case 1: model.setColor(emmet); this->name = "Emmet"; break;
        case 2: model.setColor(mat_chedar); this->name = "Mat_Cheddar";  break;
    }
}

std::string CheeseModelComponent::getName()
{
    return this->name;
}


