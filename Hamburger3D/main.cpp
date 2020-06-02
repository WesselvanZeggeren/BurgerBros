#include "Game.h"
#include "Camera.h"

using namespace cv;
using namespace std;

Game game;
Camera camera;

void frameCallback();

int main(void)
{

	if (!camera.SetUpCamera(0))
		return 1;

	double height = camera.height;
	double width = camera.width;

	game.startGame(height, width, frameCallback);

	return 0;
}

void frameCallback()
{

	Mat frame = camera.SnapShot();

	/*Mat mask = camera.getColorMask(frame, Scalar(0, 150, 150), Scalar(5, 255, 255), Scalar(175, 150, 150), Scalar(180, 255, 255));

	camera.open(mask);
	camera.close(mask);

	Point point = camera.getCenter(mask);

	circle(frame, point, 5, Scalar(0, 0, 255), -1);*/

	game.setFrame(frame);
}
