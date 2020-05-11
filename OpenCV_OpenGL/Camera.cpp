//OpenCV includes
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include "Camera.h"
	
VideoCapture cap;

Mat frame, src_gray; 

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

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);

	while (1)
	{

		bool bSuccess = cap.read(frame);
		flip(frame, frame, 3);

		if (!bSuccess)
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		imshow("MyVideo", frame);

		SnapShot();

		if (waitKey(1) == 27)
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	return 0;
}

void Camera::SnapShot()
{
	char key = cv::waitKey(30);

	if (key == 'q') {

		sprintf_s(filename, "C:/Users/maart/OneDrive/Afbeeldingen/FrameCap.jpg"); // select your folder - filename is "Frame_n"
		cv::waitKey(10);

		imshow("SnapShot", frame);
		imwrite(filename, frame);
		GetContour(60, 0);
	}
}


void Camera::GetContour(int threshold, void* )
{
	Mat contourOutput;
	vector <vector<Point>> contours;
	vector <Vec4i> hierarchy;
	cvtColor(frame, src_gray, CV_BGR2GRAY);
	Canny(src_gray, contourOutput, threshold, threshold* 2, 3);
	findContours(contourOutput, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	Mat drawing = Mat::zeros(contourOutput.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(255, 255), rng.uniform(255, 255), rng.uniform(255, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
}