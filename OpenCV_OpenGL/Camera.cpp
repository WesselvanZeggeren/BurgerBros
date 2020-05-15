//OpenCV includes
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <string>
#include "Camera.h"
	
VideoCapture cap; 

int maxThresh = 255;
char filename[100];

RNG rng(12345);

Mat frame;
Mat hsv_frame;
Mat gray_frame;

void distance(Mat& into);

void open(int amount, Mat& into);
void close(int amount, Mat& into);

void erode(int amount, Mat& into);
void dilate(int amount, Mat& into);

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

	namedWindow("Real", CV_WINDOW_AUTOSIZE);
	namedWindow("Altered", CV_WINDOW_AUTOSIZE);

	while (1)
	{

		Mat mask1, mask2, mask3;
		Mat color_only_frame;

		bool bSuccess = cap.read(frame);
		flip(frame, frame, 3);

		if (!bSuccess)
		{
		
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		imshow("Real", frame);

		cvtColor(frame, hsv_frame, COLOR_BGR2HLS);

		inRange(hsv_frame, Scalar(35, 50, 20), Scalar(50, 255, 255), mask1);
		inRange(hsv_frame, Scalar(35, 50, 20), Scalar(50, 255, 255), mask2);

		bitwise_or(mask1, mask2, mask3);

		open(1, mask3);
		close(1, mask3);

		bitwise_and(frame, frame, color_only_frame, mask3);

		imshow("Altered", color_only_frame);

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

	if (key == 'q') 
	{

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
	
	cvtColor(frame, gray_frame, CV_BGR2GRAY);
	
	Canny(gray_frame, contourOutput, threshold, threshold* 2, 3);
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

// voegt distance toe
void distance(Mat& into)
{

	Mat holder;

	distanceTransform(into, holder, DIST_L2, 3);
	normalize(holder, into, 0, 1.0, NORM_MINMAX);
}

// erode's [amount] keer en delate's daarna [amount] keer
void open(int amount, Mat& into)
{

	erode(amount, into);
	dilate(amount, into);
}

// dilate's [amount] keer en erode's daarna [amount] keer
void close(int amount, Mat& into)
{

	dilate(amount, into);
	erode(amount, into);
}

// erode functie
void erode(int amount, Mat& into)
{

	Mat holder;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, 1));

	for (int i = 0; i < amount; i++)
	{

		erode(into, holder, element);
		into = holder;
	}
}

// delate functie
void dilate(int amount, Mat& into)
{

	Mat holder;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5), Point(-1, 1));

	for (int i = 0; i < amount; i++)
	{

		dilate(into, holder, element);
		into = holder;
	}
}