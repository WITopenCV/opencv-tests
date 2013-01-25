/*
 * DisplayImage.cpp
 *
 *  Created on: Jan 25, 2013
 *      Author: Brandon DeRosier
 */

#include <opencv/cv.h>
#include <opencv/highgui.h>

int main(int argc, char** argv) {

	// Load a new image from a location specified by the first user argument.
	cv::Mat image = cv::imread(argv[1], 1);

	// If there are no user arguments or the image data hasn't been allocated,
	//   the image definitely didn't load.
	if (argc != 2 || !image.data) {
		printf("Image not loaded.\n");
		return -1;
	}

	// Start a window
	cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
	cv::imshow("Display Image", image);

	cv::waitKey(0);

	return 0;

}
