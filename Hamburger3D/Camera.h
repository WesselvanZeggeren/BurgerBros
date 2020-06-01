#pragma once

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

class Camera {

private:
	Mat frame;
	Mat hsv_frame;

public:
	VideoCapture cap;

	bool setUpCamera(int cameraNumber);
	bool startVideo(void (*callback)(Mat&));
	
	Mat getFrame();
	Mat getColorMask(Mat& frame, Scalar min, Scalar max, Scalar min2 = Scalar(0, 0, 0), Scalar max2 = Scalar(0, 0, 0));
	Mat getColor(Mat& frame, Scalar min, Scalar max, Scalar min2 = Scalar(0, 0, 0), Scalar max2 = Scalar(0, 0, 0));

	Point getCenter(Mat& frame);
	vector<Mat> getHVS(Mat& frame);

	void distance(Mat& into);
	void open(Mat& into, int amount = 1);
	void close(Mat& into, int amount = 1);
	void erode(Mat& into, int amount = 1);
	void dilate(Mat& into, int amount = 1);
};