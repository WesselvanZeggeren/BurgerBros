#include "SauceBottle.h"

SauceBottle::SauceBottle()
{
	setSauseType(0);

	model.moveBrush(0, 0.6, 0);
	model.drawRectangle(0.5, 1.2, 0.5);
	model.moveBrush(0, 0.65, 0);
	model.drawRectangle(0.4, 0.1, 0.4);
	model.moveBrush(0, 0.1, 0);
	model.drawRectangle(0.1, 0.3, 0.1);
}

SauceBottle::SauceBottle(int type)
{
	setSauseType(type);

	model.moveBrush(0, 0.6, 0);
	model.drawRectangle(0.5, 1.2, 0.5);
	model.moveBrush(0, 0.65, 0);
	model.setColor({20,20,20,1});
	model.drawRectangle(0.4, 0.1, 0.4);
	model.moveBrush(0, 0.1, 0);
	setSauseType(type);
	model.drawRectangle(0.1, 0.3, 0.1);
}


SauceBottle::~SauceBottle()
{
}

void SauceBottle::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

void SauceBottle::setSauseType(int type)
{
    Color ketchup = { 204.0,0,0, 1.0 };
    Color mustard = { 255, 219, 88, 1.0 };
    Color mayo = { 255,255,238 ,1 };

    switch (type) {
    case 0:
        model.setColor(ketchup);
        break;
    case 1:
        model.setColor(mustard);
        break;
    case 2:
        model.setColor(mayo);
        break;
    }
}

int SauceBottle::getSauseType()
{
	if (model.getColor().getVec4() == glm::vec4(204.0, 0, 0, 1.0)) {
		return 0;
	}
	if (model.getColor().getVec4() == glm::vec4(255, 219, 88, 1.0 )) {
		return 1;
	}
	if (model.getColor().getVec4() == glm::vec4(255, 255, 238, 1 )) {
		return 2;
	}
	return -1;
}
