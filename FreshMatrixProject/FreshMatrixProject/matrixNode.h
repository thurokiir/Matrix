#pragma once
#ifndef MATRIXNODE_H
#define MATRIXNODE_H



#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class matrixNode {

public:



	~matrixNode();
	matrixNode();
	matrixNode(const int & d) :data(d) {}
	matrixNode(const int & d, matrixNode * const setLeft, matrixNode * const setRight, matrixNode * const setLower,
		matrixNode * const setUpper, matrixNode * const setDeeper, matrixNode * const setHigher) :leftEntry(setLeft),
		rightEntry(setRight), upperEntry(setUpper), lowerEntry(setLower), deeperEntry(setDeeper), higherEntry(setHigher) {}

	matrixNode * getLeft();
	matrixNode * getUpper();
	matrixNode * getRight();
	matrixNode * getLower();
	matrixNode * getDeeper();
	matrixNode * getHigher();
	matrixNode * getUpperLeft();
	matrixNode * getUpperRight();
	matrixNode * getLowerLeft();
	matrixNode * getLowerRight();
	matrixNode * getNodeAt(int xAxis, int yAxis); //implementation of cartesian fetching //use diagonals //ints in the parameter

	double getData();
	double * getDataAddress();
	double getDeeperData();
	int getxAxis();
	int getyAxis();
	int getDeeperXAxis();
	int getDeeperYAxis();
	int getRed();
	int getGreen();
	int getBlue();


	void setUpper(matrixNode * newUpper);
	void setLower(matrixNode * newLower);
	void setRight(matrixNode * newRight);
	void setLeft(matrixNode * newLeft);
	void setDeeper(matrixNode * newDeeper);
	void setHigher(matrixNode * newHigher);
	void setUpperLeft(matrixNode * newUpperLeft);
	void setUpperRight(matrixNode * newUpperRight);
	void setLowerLeft(matrixNode * newLowerLeft);
	void setLowerRight(matrixNode * newLowerRight);

	void setData(double newData);
	void setColors(int red, int green, int blue);
	void setDeeperData(double newDeepData);
	void setxAxis(int xAxis);
	void setyAxis(int yAxis);
	void setDeeperXAxis(int deeperXAxis);
	void setDeeperYAxis(int deeperYaxis);

	matrixNode operator+ (const matrixNode & other);
	matrixNode operator- (const matrixNode & other);
	matrixNode operator* (const matrixNode & other);
	matrixNode operator/ (const matrixNode & other);
	matrixNode operator% (const matrixNode & other);
	//matrixNode operator++ (const matrixNode & other);
	//matrixNode operator-- (const matrixNode & other);
	//matrixNode operator= (const matrixNode & other);

private:



	double data;
	int xAxis;
	int yAxis;
	int deeperXAxis;
	int deeperYAxis;

	int redInt;
	int greenInt;
	int blueInt;

	double deeperData;

	matrixNode * leftEntry;
	matrixNode * upperEntry;
	matrixNode * rightEntry;
	matrixNode * lowerEntry;
	matrixNode * deeperEntry; //might convert matrixNode deeper and higher to Matrix. We'll see.
	matrixNode * higherEntry;

	matrixNode * upperLeftEntry;
	matrixNode * upperRightEntry;
	matrixNode * lowerLeftEntry;
	matrixNode * lowerRightEntry;

	//for the tensor implementation!
	/*
	matrixNode * northUpEastEntry;
	matrixNode * northUpWestEntry;
	matrixNode * northDownEastEntry;
	matrixNode * northDownWestEntry;
	matrixNode * southUpEastEntry;
	matrixNode * southUpWestEntry;
	matrixNode * southDownEastEntry;
	matrixNode * southDownWestEntry;
	*/
};


#endif MATRIXNODE_H
