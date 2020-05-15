#include "BaconModelComponent.h"

Color baconDarkColor = { 157,59,33 , 1 };
Color baconLightColor = { 137,0,0 , 1 };


BaconModelComponent::BaconModelComponent()
{
    model.moveBrush(0, -0.8, 0);
    //model.rotate(model, 45.0f, glm::vec3(0, 1, 0));
    for (int i = 0; i < 4; i++) {
        model.moveBrush(0, 0, 0.125);
        if (i % 2 == 1) {
            model.setColor(baconDarkColor);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
        else {
            model.setColor(baconLightColor);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
    }

    model.moveBrush(0, 0, -0.5);
    //model.rotate(model, 90.0f, glm::vec3(0, 1, 0));

    for (int i = 0; i < 4; i++) {
        model.moveBrush(0, 0, 0.125);
        if (i % 2 == 1) {
            model.setColor(baconDarkColor);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
        else
        {
            model.setColor(baconLightColor);
            model.drawRectangle(2.5, 0.05, 0.125);
        }
    }

    /* model = glm::translate(model, glm::vec3(0, -0.8, 0));
    model =glm::rotate(model, 45.0f, glm::vec3(0, 1, 0));
    for (int i = 0; i < 4; i++) {
        model = glm::translate(model, glm::vec3(0, 0,  0.125));
        tigl::shader->setModelMatrix(model);
        if (i % 2 == 1) {
            shape::drawRect(2.5, 0.05, 0.125, bacon_dark.getVec4());
        }
        else
        {
            shape::drawRect(2.5, 0.05, 0.125, bacon_light.getVec4());
        }
        
    }
    model = glm::translate(model, glm::vec3(0, 0, -0.5));
    model = glm::rotate(model, 90.0f, glm::vec3(0, 1, 0));
    for (int i = 0; i < 4; i++) {
        model = glm::translate(model, glm::vec3(0, 0, 0.125));
        tigl::shader->setModelMatrix(model);
        if (i % 2 == 1) {
            shape::drawRect(2.5, 0.05, 0.125, bacon_dark.getVec4());
        }
        else
        {
            shape::drawRect(2.5, 0.05, 0.125, bacon_light.getVec4());
        }

    }*/
}

BaconModelComponent::~BaconModelComponent()
{
}

void BaconModelComponent::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
