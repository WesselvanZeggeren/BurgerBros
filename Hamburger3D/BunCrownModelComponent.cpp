#include "BunCorwnModelComponent.h"

BunVrownModelComponent::BunVrownModelComponent()
{

}


BunVrownModelComponent::~BunVrownModelComponent()
{
    verts.push_back(Vertex::PC(position, color));


    tigl::shader->setModelMatrix(model);
    shape::drawRect(2, 0.75, 2, bread.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0, 0.6, 0)));
    shape::drawRect(1.5, 0.5, 1.5, bread.getVec4());
}

void BunVrownModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, verts);
}
