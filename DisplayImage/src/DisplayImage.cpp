/*
 * DisplayImage.cpp
 *
 * Loads an image, converts it to grayscale, writes the grayscale image
 *   to the disk, and displays both images.
 *
 *  Created on: Jan 25, 2013
 *      Author: Brandon DeRosier
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int argc, char** argv) {
	// Ensure that arguments are valid
	if (argc != 2) {
		printf("Usage: %s [image]\n", argv[0]);
		return -1;
	}

	// Load a new image from a location specified by the first user argument.
	cv::Mat image = cv::imread(argv[1], 1);

	// If the image data hasn't been allocated, the image didn't load.
	if (!image.data) {
		printf("Unable to load image: %s\n", argv[1]);
		return -1;
	}

	// Convert the image to grayscale.
	cv::Mat gray_image;
	cv::cvtColor(image, gray_image, CV_RGB2GRAY);
	// Write the image.
	cv::imwrite("gray.png", gray_image);

	// Launch two displays
	cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("Display Another Image", CV_WINDOW_AUTOSIZE);

	// Populate displays wih the images
	cv::imshow("Display Image", image);
	cv::imshow("Display Another Image", gray_image);

	// Wait for a keystroke infinitely
	cv::waitKey(0);

	return 0;
}

