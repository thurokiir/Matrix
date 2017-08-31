#pragma once
#pragma once
#ifndef MATRIXCONTROLLER_H
#define MATRIXCONTROLLER_H

#include <array>
#include "matrixNode.h"
#include "Matrix.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

/*
* the goal of this class is to do all the formatting
* of the incoming data before processing it in Matrix.
*
*/


class MatrixController {

public:

	MatrixController();

	MatrixController(const int * arrayOfNumber, const int & arrayOfNumbersSize);

	MatrixController(const int * arrayOfNumber, const int & xAxis, const int & yAxis);

	//MatrixController(vector<Vec3b*> & vectorOfNumber, int & xAxis, int & yAxis);

	int * formatTheArrayOfInts(const int * arrayOfInts, const int & chopNumber, const int & index); //The Matrix, The Size of Portions, The Number of Chops

	Matrix * generateAPictureMatrix();

	Matrix * generateAMatrix();

	Matrix * makeDeterminant(int xAxis, int yAxis);

	void divideTargetRow(Matrix & invertingMatrix, int targetRow);

	void generateAMatrix(Matrix & computation, int xAxis, int yAxis);

	void generateADeepMatrix(Matrix & theShallowMatrix, int sizeX, int sizeY, int xAxis, int yAxis);

	void printTheMatrix();

	void moveTheRoot();

	Matrix * getTheRoot();

	void setTheRoot(Matrix * newRoot);

	void weave();

	void weaveAPicture();

	void reworkAPicture();

	Matrix * weave(Matrix * weaveThisMatrix);

	Mat getThePicture();

	void skipOnce();

	void averageAPicture();

	void smoothAPicture();

private:


	Matrix * proxyMatrix = new Matrix; //use this to access functions.
	const int * testArray; //think about singletons.
	Mat thePictureMatrix;
	int * tempMatrixArray;
	int testArraySize;
	int matrixDimension;

	int matrixXAxis;
	int matrixYAxis;

	//need a Matrix? Dunno. Worth trying without it.



};


#endif