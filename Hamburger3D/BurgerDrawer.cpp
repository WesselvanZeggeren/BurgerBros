#include "BurgerDrawer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "basicShapeDrawer.h"
#include "BurgerDrawer.h"
#include "color.h"
#include <glm/gtc/matrix_transform.hpp>


Color bread = { 198.0, 137.0, 88.0, 1.0 };

Color chedar = {255.0, 166.0, 0.0, 1.0 };
Color emmet = { 255.0, 239.0, 193.0, 1.0 };
Color mat_chedar = { 247.0 ,213.0 ,143.0, 1.0 };

Color patty = { 163.0,56.0,21.0, 1.0 };

Color tomato_red = { 232.0,24.0,2.0, 1.0 };
Color tomato_red_light = { 253, 60, 39, 1.0 };

Color ketchup = { 204.0,0,0, 1.0 };
Color mustard = { 255, 219, 88, 1.0 };
Color mayo = { 255,255,238 ,1 };

void bdm::completeBurger(glm::mat4 model) {

}

void bdm::burgerBunCrown(glm::mat4 model) {
    tigl::shader->setModelMatrix(model);
    shape::drawRect(2, 0.75, 2, bread.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0, 0.6, 0)));
    shape::drawRect(1.5, 0.5, 1.5, bread.getVec4());
}
void bdm::burgerBunHeel(glm::mat4 model) {
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0, -2, 0)));
    shape::drawRect(2, 0.5, 2, bread.getVec4());
}

void bdm::burgerPatty(glm::mat4 model)
{
    model = glm::translate(model, glm::vec3(0, -1.5, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(2.3, 0.5, 1.8, patty.getVec4());
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(2.3, 0.5, 1.8, patty.getVec4());

}

void bdm::tomato(glm::mat4 model) {
    model = glm::translate(model, glm::vec3(0, -0.6, 0));
    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(1.4, 0.15, 1.0, tomato_red.getVec4());
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    shape::drawRect(1.4, 0.15, 1.0, tomato_red.getVec4());
    shape::drawRect(1, 0.16, 1, tomato_red_light.getVec4());
}
void bdm::cheese(glm::mat4 model, int type) {
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0, -1, 0)));
    if (type == 0) {
        shape::drawRect(2.1, 0.1, 2.1, chedar.getVec4());
    } 
    else if(type == 1)
    {
        shape::drawRect(2.1, 0.1, 2.1, emmet.getVec4());
    }
    else if(type == 2)
    {
        shape::drawRect(2.1, 0.1, 2.1, mat_chedar.getVec4());
    }
}
void bdm::letace(glm::mat4 model) {

}
void bdm::souce(glm::mat4 model, int type) {
    model = glm::translate(model, glm::vec3(0, 1, 0));
    tigl::shader->setModelMatrix(model);
    Color souceColor = {0,0,0,0};
    if (type == 0) {
        souceColor = ketchup;
    }
    else if (type == 1)
    {
        souceColor = mustard;
    }
    else if (type == 2) {
        souceColor = mayo;
    }

    shape::drawRect(0.4, 0.1, 0.4, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0.2, 0, 0)));
    shape::drawRect(0.1, 0.1, 0.2, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(0.2, 0, 0.1)));
    shape::drawRect(0.3, 0.1, 0.1, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(-0.2, 0, 0)));
    shape::drawRect(0.1, 0.1, 0.2, souceColor.getVec4());
    tigl::shader->setModelMatrix(glm::translate(model, glm::vec3(-0.2, 0, -0.1)));
    shape::drawRect(0.3, 0.1, 0.1, souceColor.getVec4());
}
void bdm::dicedUnions(glm::mat4 model) {

}

void bdm::pickle(glm::mat4 model)
{
}

void bdm::bacon(glm::mat4 model)
{
}

void bdm::egg(glm::mat4 model)
{
}
