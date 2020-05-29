#include "../Hamburger3D/tigl.h"
#include "..\Hamburger3D\basicShapeDrawer.h"
using tigl::Vertex;


void shape::drawTriangle() {
    tigl::begin(GL_TRIANGLES);
    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(1, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(1, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), glm::vec4(0, 0, 1, 1)));

    tigl::end();
}

void shape::drawSquare() {
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), glm::vec4(0, 0, 1, 1)));
    tigl::end();
}

void shape::drawDiamond() {
    tigl::begin(GL_TRIANGLE_FAN);
    tigl::addVertex(Vertex::PC(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, 0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, -0.75f), glm::vec4(1, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, -0.75f), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1.0f, 0.5f, 0.0f), glm::vec4(0, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, 0.75f), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, 0.75f), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, 0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));

    tigl::end();
    tigl::begin(GL_TRIANGLE_FAN);

    tigl::addVertex(Vertex::PC(glm::vec3(0.0f, -1.0f, 0.0f), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, -0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, -0.75f), glm::vec4(1, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, -0.75f), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1.0f, -0.5f, 0.0f), glm::vec4(0, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, 0.75f), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, 0.75f), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, -0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));
    tigl::end();

    tigl::begin(GL_QUAD_STRIP);

    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, -0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, 0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, -0.75f), glm::vec4(1, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, -0.75f), glm::vec4(1, 1, 0, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, -0.75f), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, -0.75f), glm::vec4(0, 1, 0, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-1.0f, -0.5f, 0.0f), glm::vec4(0, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-1.0f, 0.5f, 0.0f), glm::vec4(0, 1, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, 0.75f), glm::vec4(0, 0, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, 0.75f), glm::vec4(0, 0, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, 0.75f), glm::vec4(0, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, 0.75f), glm::vec4(0, 0, 0, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, -0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(1.0f, 0.5f, 0.0f), glm::vec4(1, 0, 0, 1)));

    tigl::end();
}

//W.I.P Not neccecary & doesnt work
void shape::drawCilinder(double x, double y, double z, glm::vec4 color, float smoothnes) {
    float fineness = 360.0f / 4.0f;
    fineness /= smoothnes;

    double PI = 3.1415926535;

    tigl::begin(GL_TRIANGLE_STRIP);

    for (float i = 0; i < 365; i += fineness) {
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f) * x / 2,
            -y / 2,
            glm::sin(i * PI / 180.0f) * z / 2),
            color));
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f) * x / 2,
            y / 2,
            glm::sin(i * PI / 180.0f) * z / 2),
            color));
    }

    tigl::end();

    tigl::begin(GL_TRIANGLE_FAN);
    for (float i = 0; i < 365; i += fineness) {
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f),
            -y / 2,
            glm::sin(i * PI / 180.0f)),
            color));
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f),
            y / 2,
            glm::sin(i * PI / 180.0f)),
            color));
    }
    tigl::end();
}

//W.I.P XYZ controll doesnt work
void shape::drawCircle(double x, double y, double z, glm::vec4 color, float smoothnes) {
    float fineness = 360.0f / 4.0f;
    fineness /= smoothnes;

    double PI = 3.1415926535;

    tigl::begin(GL_TRIANGLE_FAN);
    for (float i = 0; i < 365; i += fineness) {
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f),
            -y / 2,
            glm::sin(i * PI / 180.0f)),
            color));
    }
    tigl::end();
}

void shape::drawRect(double x, double y, double z, glm::vec4 color) {
    tigl::begin(GL_QUADS);
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), -(y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), (y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), (y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), -(y / 2), -(z / 2)), color));

    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), -(y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), (y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), (y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), -(y / 2), (z / 2)), color));

    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), -(y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), (y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), (y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), -(y / 2), (z / 2)), color));

    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), -(y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), (y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), (y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), -(y / 2), (z / 2)), color));

    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), -(y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), -(y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), -(y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), -(y / 2), -(z / 2)), color));

    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), (y / 2), -(z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3(-(x / 2), (y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), (y / 2), (z / 2)), color));
    tigl::addVertex(Vertex::PC(glm::vec3((x / 2), (y / 2), -(z / 2)), color));
    tigl::end();
}

//W.I.P XYZ controll doesnt work
void shape::drawTube(double x, double y, double z, glm::vec4 color, float smoothnes)
{
    float fineness = 360.0f / 4.0f;
    fineness /= smoothnes;

    double PI = 3.1415926535;

    tigl::begin(GL_TRIANGLE_STRIP);

    for (float i = 0; i < 365; i += fineness) {
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f),
            -y / 2,
            glm::sin(i * PI / 180.0f)),
            color));
        tigl::addVertex(Vertex::PC(glm::vec3(
            glm::cos(i * PI / 180.0f),
            y / 2,
            glm::sin(i * PI / 180.0f)),
            color));
    }
    tigl::end();
}

