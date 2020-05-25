#include "ScreenMOdelComponent.h"

ScreenMOdelComponent::ScreenMOdelComponent()
{
    //Color white = {1, 1, 1, 1};
    //glm::vec3 normal = glm::vec3(1, 1, 1);
	//verts.push_back(Vertex::PCTN(glm::vec3(-10.5, -8, 0),  white.getVec4(), glm::vec2(0, 0), normal));
    //verts.push_back(Vertex::PCTN(glm::vec3(10.5, -8, 0),  white.getVec4(), glm::vec2(1, 0), normal));
    //verts.push_back(Vertex::PCTN(glm::vec3(10.5, 8, 0),  white.getVec4(), glm::vec2(1, -1), normal));
    //verts.push_back(Vertex::PCTN(glm::vec3(-10.5, 8, 0),  white.getVec4(), glm::vec2(0, -1), normal));

    double y = 4;
    double x = 6;
    
    verts.push_back(Vertex::PT(glm::vec3(-x, -y, 0), glm::vec2(0, 0)));
    verts.push_back(Vertex::PT(glm::vec3(x, -y, 0), glm::vec2(1, 0)));
    verts.push_back(Vertex::PT(glm::vec3(x, y, 0), glm::vec2(1, -1)));
    verts.push_back(Vertex::PT(glm::vec3(-x, y, 0), glm::vec2(0, -1)));
    
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

    glDisable(GL_TEXTURE_2D);

    tigl::shader->enableTexture(false);
    tigl::shader->enableAlphaTest(false);
}
