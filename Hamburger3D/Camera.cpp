//OpenCV includes
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include "Camera.h"
#include "GameObject.h"
#include "Game.h"

Point point;

VideoCapture cap;

Mat image, frame, src_gray, imgThresholded;

RNG rng[123456];

int maxThresh = 255;

int Camera::SetUpCamera(int cameraNumber)
{
	cap.open(cameraNumber);

	if (!cap.isOpened())
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "Frame size : " << width << " x " << height << endl;

	return 0;
}

Mat Camera::SnapShot()
{
	bool bSuccess = cap.read(image);

	if (!bSuccess)
	{
		cout << "Cannot read a frame from video stream" << endl;
	}
	else
	{
		flip(image, image, 3);
		cvtColor(image, frame, CV_BGR2RGB);
	}
	
	return frame;
}

void Camera::GetExtreme(vector<Point> cnt, Mat image)
{
	// compare x axis
	auto val = std::minmax_element(cnt.begin(), cnt.end(), [](Point const& a, Point const& b) {
		return a.x < b.x;
		});

	std::cout << " leftMost [ " << val.first->x << ", " << val.first->y << " ]" << std::endl;
	std::cout << " RightMost [ " << val.second->x << ", " << val.second->y << " ]" << std::endl;
	Point left = Point(val.first->x, val.first->y);
	Point right = Point(val.second->x, val.second->y);
	circle(image, left, 50, Scalar(255, 0, 0), CV_FILLED, 8, 0);
	circle(image, right, 50, Scalar(255, 0, 0), CV_FILLED, 8, 0);

	// compare y axis
	val = std::minmax_element(cnt.begin(), cnt.end(), [](Point const& a, Point const& b) {
		return a.y < b.y;
		});

	std::cout << " TopMost [ " << val.first->x << ", " << val.first->y << " ]" << std::endl;
	std::cout << " BottomMost [ " << val.second->x << ", " << val.second->y << " ]" << std::endl;
	Point top = Point(val.first->x, val.first->y);
	Point bottom = Point(val.second->x, val.second->y);
	circle(image, top, 50, Scalar(255, 0, 0), CV_FILLED, 8, 0);
	circle(image, bottom, 50, Scalar(255, 0, 0), CV_FILLED, 8, 0);
	imshow("Points", image);

}

Point Camera::GetCenter(int lowHue, int highHue)
{
	int iLastX = -1;
	int iLastY = -1;

	int lowSat = 150;
	int highSat = 255;

	int lowVal = 60;
	int highVal = 255;

	Mat imgHSV;

	cvtColor(frame, imgHSV, COLOR_BGR2HSV);

	inRange(imgHSV, Scalar(lowHue, lowSat, lowVal), Scalar(highHue, highSat, highVal), imgThresholded);


	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

	Moments oMoments = moments(imgThresholded);
	double dM01 = oMoments.m01;
	double dM10 = oMoments.m10;
	double dArea = oMoments.m00;
	Point center;

	if (dArea > 10000)
	{
		int posX = dM10 / dArea;
		int posY = dM01 / dArea;

		if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
		{
			center = Point(posX, posY);
			cout << Point(posX, posY) << endl;
			circle(frame, center, 10, Scalar(0, 0, 255), 1);

		}

		iLastX = posX;
		iLastY = posY;
	}

	imshow("Thresholded Image", imgThresholded);
	imshow("Original", frame);

	return center;
}

void Camera::AttachIngredient()
{
	double radius = 20;
	point = GetCenter(75, 130);
	Game game;
	for (GameObject *object : game.ingredients)
	{
		if ((pow((point.x - object->position.x), 2) + pow((point.y - object->position.y), 2)) < pow(radius, 2))
		{
			object->setAttached(true);
		}
	}
}

void Camera::isAttached()
{
	Game game;
	for (GameObject* object : game.ingredients)
	{
		if (object->attached)
		{
			object->position.x = point.x;
			object->position.y = point.y;

		}
	}
}

