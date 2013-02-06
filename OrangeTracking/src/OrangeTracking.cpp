// Code originally from:
// http://opencv-srf.blogspot.com/2010/09/object-detection-using-color-seperation.html

#include <stdio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

IplImage* GetThresholdedImage(IplImage* imgHSV){
       IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
       cvInRangeS(imgHSV, cvScalar(170,160,60), cvScalar(180,256,256), imgThresh);
       return imgThresh;
}

int main(int argc, char** argv) {
	// Define a capture handle
	CvCapture* capture = 0;

	// Assign the first camera to the capture handle
	capture = cvCaptureFromCAM(0);
	if (!capture) {
		printf("Unable to hook camera.\n");
		return -1;
	}

	// Define a handle for each capture frame
	IplImage* frame = 0;

	// Start display windows
	cvNamedWindow("Raw"); // One for the raw video
	cvNamedWindow("Tracking"); // And another for the actual processing

	// Capture and process frames
	while(true) {
		// Capture a frame
		frame = cvQueryFrame(capture);
		if (!frame) break;

		frame = cvCloneImage(frame);
		cvSmooth(frame, frame, CV_GAUSSIAN, 3, 3); // Gaussian smooth

		// Convert the frame to an HSV image
		IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
		cvCvtColor(frame, imgHSV, CV_BGR2HSV);
		IplImage* imgThresh = GetThresholdedImage(imgHSV);

		cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN, 3, 3); //smooth the binary image using Gaussian kernel

		cvShowImage("Ball", imgThresh);
		cvShowImage("Video", frame);

		// Clean up used images
		cvReleaseImage(&imgHSV);
		cvReleaseImage(&imgThresh);
		cvReleaseImage(&frame);

		// Wait 50mS
		int c = cvWaitKey(10);
		// If 'ESC' is pressed, break the loop
		if ((char)c==27) break;
	}
}
