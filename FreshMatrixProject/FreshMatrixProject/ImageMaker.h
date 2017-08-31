#pragma once

#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

class ImageMaker {

public:

	ImageMaker();
	~ImageMaker();

	Mat * baseImage();
	void showThePicture(Mat * renderThis);

private:

	Mat * privateImage = new Mat();
};

#endif