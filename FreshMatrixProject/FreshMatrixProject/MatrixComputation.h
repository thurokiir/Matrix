#pragma once
#ifndef MATRIXCOMPUTATION_H
#define MATRIXCOMPUTATION_H

#include "matrixNode.h"
#include "Matrix.h"
#include "MatrixController.h"


//might need to declare friend to MatrixController here

class MatrixComputation {



public:




	MatrixComputation();
	~MatrixComputation();

	//http://www.intmath.com/matrices-determinants/inverse-matrix-gauss-jordan-elimination.php
	Matrix * inverseMatrix(Matrix * invertThis);
	Matrix * crossProduct(matrixNode * left, matrixNode * right, int matrixXAxis, int matrixYAxis);
	Matrix * dotProduct(matrixNode * left, matrixNode * right, int matrixXAxis, int matrixYAxis);
	Matrix * multiplyProduct(matrixNode * left, matrixNode * right, int matrixXAxis, int matrixYAxis);




private:

	matrixNode * storageOne;
	matrixNode * storageTwo;

	Matrix * processOne = new Matrix;


};





#endif MATRIXCOMPUTATION_H