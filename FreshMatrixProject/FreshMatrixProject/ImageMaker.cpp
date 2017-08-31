#include "ImageMaker.h"

using namespace cv;
using std::cout;
using std::endl;
using std::vector;

ImageMaker::ImageMaker() {
	this->privateImage = nullptr;
}

ImageMaker::~ImageMaker() {}

Mat * ImageMaker::baseImage() {

	Mat importImage = imread("NightsAllNight.jpg", IMREAD_COLOR); // Read the file

	privateImage = &importImage; //2x check this later for continuity / save states

	if (privateImage->empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;

		return nullptr;
	}

	return privateImage;



}

void ImageMaker::showThePicture(Mat * renderThis) {

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.

	imshow("Display window", *renderThis); // Show our image inside it.

}