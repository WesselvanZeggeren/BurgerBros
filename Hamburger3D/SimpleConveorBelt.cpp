#include "SimpleConveorBelt.h"

SimpleConveorBelt::SimpleConveorBelt()
{
	Color temp = { 0,0,0 };

	model.setColor(temp);
	model.moveBrush(0,0.25,0);
	model.drawRectangle(5, 0.5, 2);
}

SimpleConveorBelt::~SimpleConveorBelt()
{
}

void SimpleConveorBelt::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}
