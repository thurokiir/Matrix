#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include "matrixNode.h"



class Matrix {


public:

	Matrix();
	~Matrix();

	matrixNode * createNode(const double & matrixValue);
	matrixNode * makeARow(int * makeMe, int size);
	matrixNode * getRoot();
	int getDepthCount();
	int getMatrixXAxis();
	int getMatrixYAxis();

	void setRoot(matrixNode * newRoot);
	void setMatrixXAxis(int x);
	void setMatrixYAxis(int y);

	void printMatrix();
	void setDepthCount(int newDepth);
	void goDeeperConventional(int sizeX, int sizeY); //the function to push this project to a third dimension
	void goDeeperConventional(matrixNode & shallowNode, int sizeX, int sizeY, int deeperXAxis, int deeperYAxis);
	void diagonalWeave(int sizeX, int sizeY);
	void diagonalWeave(matrixNode & oneDimensional, int sizeX, int sizeY);
	void goDeeperRecursive();
	void returnToTopLeft(matrixNode & bottomRightNode, int sizeX, int sizeY);
	void weaveANode(matrixNode & selectedUpperLeftNode, int sizeX, int sizeY);
	void bindMetaNodes(Matrix & theRootMatrix, int xAxis, int yAxis);
	void bindSubNodes(matrixNode * firstNode, matrixNode * secondNode, int cardinal);
	void bindShallowNodes(Matrix * firstNode, Matrix * secondNode, int cardinal);
	void metaTraverse(); //will be overloading this with various inputs.
	void nodeTraverse(matrixNode * target); //yAxis to know how many rows to go down


private:

	matrixNode * rootNode = new matrixNode();  //ask Andy about this vs nullptr via constructor
	int matrixXAxis;
	int matrixYAxis;
	int depthCount;

};



#endif MATRIX_H