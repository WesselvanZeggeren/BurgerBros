#include "ScreenMOdelComponent.h"
#include <iostream>

ScreenMOdelComponent::ScreenMOdelComponent()
{

    double y = 16;
    double x = 20;
    double z = -25;
    
    verts.push_back(Vertex::PT(glm::vec3(-x, -y, z), glm::vec2(0, 0)));
    verts.push_back(Vertex::PT(glm::vec3(x, -y, z), glm::vec2(1, 0)));
    verts.push_back(Vertex::PT(glm::vec3(x, y, z), glm::vec2(1, -1)));
    verts.push_back(Vertex::PT(glm::vec3(-x, y, z), glm::vec2(0, -1)));
    
}

ScreenMOdelComponent::~ScreenMOdelComponent()
{


}

void ScreenMOdelComponent::draw()
{
    tigl::shader->enableTexture(true);
    tigl::shader->enableColor(true);
    tigl::shader->enableAlphaTest(true);

    tigl::drawVertices(GL_QUADS, verts);

    tigl::shader->enableTexture(false);
    tigl::shader->enableAlphaTest(false);

}
