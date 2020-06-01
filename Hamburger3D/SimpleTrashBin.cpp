#include "SimpleTrashBin.h"

SimpleTrashBin::SimpleTrashBin()
{
	Color lightGray = {144,144,144};
	Color darkGray = {99,99,99};
	Color recycleLogo = { 2, 105, 40 };

	model.setColor(darkGray);
	model.moveBrush(0, 0.6, 0);
	model.drawRectangle(1, 1.2, 1);

	//model.setColor(recycleLogo);
	//model.drawRectangle(0.2, 0.2, 1.05);
	//model.drawRectangle(1.05, 0.2, 0.2);

	model.setColor(lightGray);
	model.moveBrush(0.225, 0, 0);
	model.drawRectangle(0.15, 1, 1.05);
	model.moveBrush(-0.45, 0, 0);
	model.drawRectangle(0.15, 1, 1.05);
	model.moveBrush(0.225, 0, 0);

	model.moveBrush(0, 0, 0.225);
	model.drawRectangle(1.05, 1, 0.15);
	model.moveBrush(0, 0, -0.45);
	model.drawRectangle(1.05, 1, 0.15);
	model.moveBrush(0, 0, 0.225);

	//model.drawRectangle(1.05, 1, 0.15);


	model.setColor(darkGray);

	model.moveBrush(0, 0.8, 0);
	model.drawRectangle(0.8, 0.19, 0.8);

	model.setColor(lightGray);
	model.moveBrush(0, -0.1, 0);
	model.drawRectangle(1.1, 0.1, 1.1);

	model.moveBrush(0, 0.25, 0);
	model.drawRectangle(0.1, 0.1, 0.3);

}

SimpleTrashBin::~SimpleTrashBin()
{
}

void SimpleTrashBin::draw()
{
	tigl::drawVertices(GL_QUADS, model.getVertacies());
}

void SimpleTrashBin::setSauseType(int type)
{
}
