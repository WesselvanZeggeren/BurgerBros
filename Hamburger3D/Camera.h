#pragma once
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

class Camera {

public:
	double width, height;
	int SetUpCamera(int cameraNumber);
	void GetContour(int, void*);
	Mat SnapShot();
	void isAttached();
	void GetExtreme(std::vector<Point> cnt, Mat image);
	Point GetCenter(int lowHue, int highHue);
};