#include "Game.h"
#include "Camera.h"

using namespace cv;
using namespace std;

Game game;
Camera camera;

int main(void)
{
	camera.SetUpCamera(0);

	game.startGame(camera.height, camera.width, camera);

	return 0;
}
