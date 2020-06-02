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

Mat frame, src_gray, imgThresholded;

int maxThresh = 255;

RNG rng(12345);

char filename[100];

int Camera::SetUpCamera(int cameraNumber)
{
	cap.open(cameraNumber);


	if (!cap.isOpened())
	{
		cout << "Cannot open the video cam" << endl;
		return -1;
	}

	double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "Frame size : " << width << " x " << height << endl;


	while (1)
	{

		bool bSuccess = cap.read(frame);

		if (!bSuccess)
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		//GetContour(60, 0);

		//SnapShot();
		cout << GetCenter(75, 130) << endl;

		if (waitKey(1) == 27)
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}

Mat Camera::SnapShot()
{
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


void Camera::GetContour(int threshold, void*)
{
	Mat contourOutput;
	vector <vector<Point>> contours;
	vector <Vec4i> hierarchy;
	cvtColor(frame, src_gray, CV_BGR2GRAY);
	Canny(src_gray, contourOutput, threshold, threshold * 2, 3);
	findContours(contourOutput, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	Mat drawing = Mat::zeros(contourOutput.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(255, 255), rng.uniform(255, 255), rng.uniform(255, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
	vector<Point> cnt;
	for (int i = 0; i < contours.size(); i++)
	{
		for (int j = 0; j < contours[i].size();j++) // run until j < contours[i].size();
		{
			Point point = contours[i][j];
			cnt.push_back(point);
		}
	}
	GetExtreme(cnt, contourOutput);
}