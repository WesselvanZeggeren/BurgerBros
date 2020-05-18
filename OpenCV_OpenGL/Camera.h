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
		int SetUpCamera(int cameraNumber);
		void GetContour(int, void* );
		void SnapShot();
		void GetExtreme(std::vector<Point> cnt, Mat image);
};