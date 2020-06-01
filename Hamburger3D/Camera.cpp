#include <iostream>
#include <string>
#include "Camera.h"

bool Camera::setUpCamera(int cameraNumber)
{

	cap.open(cameraNumber);

	return (cap.isOpened());
}

bool Camera::startVideo(void (*callback)(Mat&))
{

	while (1)
	{

		Mat frame = getFrame();

		callback(frame);

		if (waitKey(1) == 27)
		{

			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;
}

Mat Camera::getFrame()
{

	bool bSuccess = cap.read(frame);
	flip(frame, frame, 3);

	if (!bSuccess)
		cout << "Cannot read a frame from video stream" << endl;

	return frame;
}

Mat Camera::getColorMask(Mat& frame, Scalar min, Scalar max, Scalar min2, Scalar max2)
{

	Mat hsv_frame;
	Mat firstMask, secondMask, bothMasks;

	cvtColor(frame, hsv_frame, COLOR_BGR2HLS);

	inRange(hsv_frame, min, max, firstMask);
	inRange(hsv_frame, min2, max2, secondMask);

	bitwise_or(firstMask, secondMask, bothMasks);

	return bothMasks;
}

Mat Camera::getColor(Mat& frame, Scalar min, Scalar max, Scalar min2, Scalar max2)
{

	Mat color_frame;

	bitwise_and(frame, frame, color_frame, getColorMask(frame, min, max, min2, max2));

	return color_frame;
}

Point Camera::getCenter(Mat& frame)
{

	Mat bin_frame;

	threshold(frame, bin_frame, 0.5, 1, THRESH_BINARY);

	Moments m = moments(bin_frame, true);

	return Point(int(m.m10 / m.m00), int(m.m01 / m.m00));
}

vector<Mat> Camera::getHVS(Mat& frame)
{

	Mat hsv_frame;
	vector<Mat> channels;

	cvtColor(frame, hsv_frame, COLOR_BGR2HLS);
	split(hsv_frame, channels);

	return channels;
}

// voegt distance toe
void Camera::distance(Mat& into)
{

	Mat holder;

	distanceTransform(into, holder, DIST_L2, 3);
	normalize(holder, into, 0, 1.0, NORM_MINMAX);
}

// erode's [amount] keer en delate's daarna [amount] keer
void Camera::open(Mat& into, int amount)
{

	erode(into, amount);
	dilate(into, amount);
}

// dilate's [amount] keer en erode's daarna [amount] keer
void Camera::close(Mat& into, int amount)
{

	dilate(into, amount);
	erode(into, amount);
}

// erode functie
void Camera::erode(Mat& into, int amount)
{

	Mat holder;
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, 1));

	for (int i = 0; i < amount; i++)
	{

		cv::erode(into, holder, element);
		into = holder;
	}
}

// delate functie
void Camera::dilate(Mat& into, int amount)
{

	Mat holder;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5), Point(-1, 1));

	for (int i = 0; i < amount; i++)
	{

		cv::dilate(into, holder, element);
		into = holder;
	}
}