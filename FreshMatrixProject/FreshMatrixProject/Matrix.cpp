#include "Matrix.h"



Matrix::Matrix() {
	this->rootNode = nullptr;
	this->depthCount = 0;
}
Matrix::~Matrix() {

}
matrixNode * Matrix::createNode(const double & matrixValue) { //convert this to generics later
	matrixNode * test = new matrixNode();
	test->setData(matrixValue);
	return test;
}
matrixNode * Matrix::getRoot() {
	return rootNode;
}
int Matrix::getDepthCount() {
	return this->depthCount;
}
int Matrix::getMatrixXAxis() {
	return this->matrixXAxis;
}
int Matrix::getMatrixYAxis() {
	return this->matrixYAxis;
}

void Matrix::setRoot(matrixNode * newRoot) {
	this->rootNode = newRoot;
}
void Matrix::setMatrixXAxis(int x) {
	this->matrixXAxis = x;
}
void Matrix::setMatrixYAxis(int y) {
	this->matrixYAxis = y;
}
void Matrix::setDepthCount(int depth) {
	this->depthCount = depth;
}


matrixNode * Matrix::makeARow(int * makeMe, int size) {

	int proxySize = size;
	int arrayPosition = 0;
	int leadNodeMoveInt = 0;
	matrixNode * leadNode;
	matrixNode * backNode;
	matrixNode * tracker = new matrixNode();

	while (proxySize != 0) {
		leadNode = createNode(makeMe[arrayPosition]);

		if (tracker != nullptr) {
			leadNode->setLeft(tracker);
			leadNode->getLeft()->setRight(leadNode);
		}

		tracker = leadNode;
		leadNode = leadNode->getRight();
		proxySize--;
		arrayPosition++;
	}

	leadNode = new matrixNode();
	backNode = new matrixNode();

	tracker->setRight(leadNode);
	tracker->getRight()->setLeft(tracker);
	tracker = tracker->getRight();

	while (leadNodeMoveInt < size) {
		leadNode = leadNode->getLeft();
		leadNodeMoveInt++;
	}

	leadNode->setLower(backNode);
	leadNode->getLower()->setUpper(leadNode);
	leadNode = leadNode->getLower();

	tracker = new matrixNode();
	return leadNode;
}

void Matrix::printMatrix() {  //attempt a recursive version of this at a later date

	matrixNode * tempXNode = rootNode;
	matrixNode * tempYNode = rootNode;

	cout << "From left to right then from up to down" << endl;
	while (tempYNode != nullptr) {

		while (tempXNode != nullptr) {
			cout << tempXNode->getData() << " ";
			tempXNode = tempXNode->getRight();
		}
		cout << endl;
		cout << endl;
		tempYNode = tempYNode->getLower();
		tempXNode = tempYNode;
	}

}

void Matrix::goDeeperConventional(int sizeX, int sizeY) {

	matrixNode * theDepthNode = new matrixNode();
	matrixNode * depthLead = new matrixNode();

	//test logic, replace with iterative code that delves to appropriate depth
	float doubleTest = static_cast<float>(1) / 9;
	theDepthNode->setDeeperData(doubleTest);
	rootNode->setDeeper(theDepthNode);
	rootNode->getDeeper()->setHigher(rootNode);
	//end of test logic
	matrixNode * depthTemp = theDepthNode;
	int track = 0;
	int reset = 1;
	int dimensionalProduct = sizeX * sizeY;
	theDepthNode->setDeeperData(static_cast<float>(track) / dimensionalProduct);


	//making a better version of what we did in matrix controller
	while (track != dimensionalProduct) {

		if (track % (sizeX) == 0 && track > 0) { //return depthlead to zeroth position, ask andy the most effective way of doing this
			while (reset <= sizeX) { //now iterating correctly with a <, <= gives a nullptr
				theDepthNode = theDepthNode->getLeft();
				reset++;
			}

			depthLead = new matrixNode();

			depthLead->setUpper(theDepthNode);
			depthLead->setDeeperData(static_cast<float>(track) / dimensionalProduct);
			theDepthNode->setLower(depthLead);
			theDepthNode = theDepthNode->getLower();
			reset = 1;
		}
		depthLead = new matrixNode();
		depthLead->setDeeperData(static_cast<float>(track + 1) / dimensionalProduct);
		depthLead->setLeft(theDepthNode);
		theDepthNode->setRight(depthLead);
		theDepthNode = theDepthNode->getRight();

		track++;

	}

	returnToTopLeft(*theDepthNode, sizeX, sizeY);
	weaveANode(*theDepthNode, sizeX, sizeY);

}

//improving on what we did above
void Matrix::goDeeperConventional(matrixNode & shallowNode, int sizeX, int sizeY, int deeperXAxis, int deeperYAxis) {


	int track = 0;
	int xAxis = 0;
	int yAxis = 0;


	int xAxisCounter = 1;
	int yAxisCounter = 0;
	int xAxisCopy = deeperXAxis;
	int yAxisCopy = deeperYAxis;
	int reset = 0;

	int dimensionalProduct = deeperXAxis * deeperYAxis;
	//cout << "shallowNode.getData(): " << shallowNode.getData() << endl;
	double relativeDouble = (static_cast<float>(track) / dimensionalProduct) + static_cast<float>(shallowNode.getData());

	shallowNode.setxAxis(deeperXAxis);
	shallowNode.setyAxis(deeperYAxis);

	matrixNode * theShallowNode;
	theShallowNode = &shallowNode; //stores the value of the node we are passing in to deepen.

	matrixNode * deepRoot;
	matrixNode * leadNode = new matrixNode();
	matrixNode * anchorNode = new matrixNode();

	leadNode->setDeeperData(relativeDouble); //dont forget to check if shallowNode.Data is working with the float
	leadNode->setHigher(theShallowNode);
	theShallowNode->setDeeper(leadNode); //sets the value of the stored node's deeper field
	deepRoot = shallowNode.getDeeper();
	deepRoot->setxAxis(xAxis);
	deepRoot->setyAxis(yAxis);

	while (yAxisCounter != deeperYAxis - 1) { //makes the "spine" of the matrix along the left hand side
		leadNode = new matrixNode();
		yAxisCounter++;
		leadNode->setyAxis(yAxisCounter);
		leadNode->setxAxis(0);
		leadNode->setDeeperData((static_cast<float>(track += deeperYAxis) / dimensionalProduct) + static_cast<float>(shallowNode.getData()));
		leadNode->setUpper(deepRoot);
		deepRoot->setLower(leadNode);
		deepRoot = deepRoot->getLower();
	}

	yAxisCounter = 0;

	while (deepRoot->getUpper() != nullptr) { //puts deepRoot back to 0,0
		deepRoot = deepRoot->getUpper();
	}

	track = 0;

	while (reset != deeperYAxis) {//iterates down the "spine"
		while (xAxisCounter != deeperXAxis) {//iterates to the "right" to form "ribs"
			leadNode = new matrixNode();
			anchorNode = deepRoot;
			leadNode->setxAxis(xAxisCounter);
			leadNode->setyAxis(anchorNode->getyAxis());

			leadNode->setLeft(deepRoot);
			deepRoot->setRight(leadNode);
			leadNode->setDeeperData((static_cast<float>(1) / dimensionalProduct) + deepRoot->getDeeperData());
			deepRoot = deepRoot->getRight();
			xAxisCounter++;
		}

		while (deepRoot->getLeft() != nullptr) { //we have moved deeproot back
												 //cout << "deepRoot->getDeeperData(): " << deepRoot->getDeeperData() << endl; //prints out all contents of the matrix
			deepRoot = deepRoot->getLeft();
		}

		if (deepRoot->getLower() != nullptr) { //move deep root down one row. Causing issues with Y-Axis <= 2
			deepRoot = deepRoot->getLower();
		}

		if (yAxis == 2) {
			deepRoot = deepRoot->getLower();
		}

		xAxisCounter = 1; //RESET THE CLOCK
		reset++;
	}


	while (deepRoot->getUpper() != nullptr) { //move deepRoot back to the topLeft of the matrix
		deepRoot = deepRoot->getUpper();
	}

	weaveANode(*deepRoot, deeperXAxis, deeperYAxis); // bind the family of nodes in E,W,N,S
	diagonalWeave(*deepRoot, deeperXAxis, deeperYAxis);  //bind the family of nodes in NW,NE,SW,SE

}

void Matrix::goDeeperRecursive() {
}

void Matrix::weaveANode(matrixNode & selectedUpperRightNode, int sizeX, int sizeY) {

	int trackX = 0;
	int trackY = 0;

	matrixNode * theNodeAbove;
	theNodeAbove = (&selectedUpperRightNode);

	matrixNode * theNodeBelow;
	theNodeBelow = selectedUpperRightNode.getLower();

	matrixNode * theNodeStart = theNodeAbove;
	matrixNode * theNodeBelowStart = theNodeBelow;

	while (trackY != sizeY) {

		while (trackX != sizeX) { //can bedone with a single iterator however sticking with prototype to ensure double checking of work

			theNodeAbove->setLower(theNodeBelow);
			if (theNodeBelow != nullptr) {
				theNodeBelow->setUpper(theNodeAbove);
			}

			theNodeAbove = theNodeAbove->getRight();
			theNodeBelow = theNodeBelow->getRight();

			trackX++;
		}

		trackX = 0;
		if (theNodeBelowStart != nullptr) { //the issue with the incorrectly bonded nodes is here, i think it is because of yAxis <= 2
			theNodeStart = theNodeStart->getLower();
			theNodeBelowStart = theNodeBelowStart->getLower();

			theNodeAbove = theNodeStart;
			theNodeBelow = theNodeBelowStart;
		}
		trackY++;
	}
}

void Matrix::returnToTopLeft(matrixNode & bottomLeftNode, int sizeX, int sizeY) {
	int trackX = 0;
	int trackY = 0;
	matrixNode * testNode;

	while (trackX != sizeX) {
		testNode = bottomLeftNode.getLeft();
		bottomLeftNode = *testNode;
		trackX++;
	}

	while (trackY != sizeY - 1) {
		testNode = bottomLeftNode.getUpper();
		bottomLeftNode = *testNode;
		trackY++;
	}

	//works perfectly. This is an excellent example of taking a data structure
	//and modifying it by reference. I dont HAVE to use testNode either. Will test later.


}

void Matrix::diagonalWeave(int sizeX, int sizeY) { //for matrices made using MatrixController

}

void Matrix::diagonalWeave(matrixNode & oneDimensional, int sizeX, int sizeY) { //for all those nested buggers

																				//cout << oneDimensional.getDeeperData() << " ";

	int trackX = 0;
	int trackY = 0;

	matrixNode * referenceNode = (&oneDimensional);
	matrixNode * anchorNode = (&oneDimensional);


	matrixNode * theReferenceNode = referenceNode;
	matrixNode * theAnchoringNode = anchorNode;


	while (trackY != sizeY) { //might need to change all the oneDimensional references to referenceNode

		while (trackX != sizeX) {

			if (referenceNode->getLeft() != nullptr && referenceNode->getUpper() != nullptr) {
				referenceNode->setUpperLeft(referenceNode->getLeft()->getUpper());
			}
			if (referenceNode->getRight() != nullptr && referenceNode->getUpper() != nullptr) {
				referenceNode->setUpperRight(referenceNode->getRight()->getUpper());
			}
			if (referenceNode->getLeft() != nullptr && referenceNode->getLower() != nullptr) {
				referenceNode->setLowerLeft(referenceNode->getLeft()->getLower());
			}
			if (referenceNode->getRight() != nullptr && referenceNode->getLower() != nullptr) {
				referenceNode->setLowerRight(referenceNode->getRight()->getLower());
			}

			referenceNode = referenceNode->getRight();
			trackX++;
		}
		trackX = 0;

		anchorNode = anchorNode->getLower();
		referenceNode = anchorNode;

		theAnchoringNode = theAnchoringNode->getLower();
		theReferenceNode = theReferenceNode->getLower();
		//if (referenceNode->getLeft() == nullptr) {
		//	cout << "deeperData" << referenceNode->getDeeperData() << endl;
		//	cout << "getLeft == nullptr" << endl;
		//}
		trackY++;
	}

}

void Matrix::bindMetaNodes(Matrix & theRootMatrix, int xAxis, int yAxis) {

	Matrix * delveDeeper = (&theRootMatrix);
	matrixNode * currentNode = (&theRootMatrix)->getRoot();
	matrixNode * neighborNode = (&theRootMatrix)->getRoot(); //initialized, move this relative to current node.
	matrixNode * anchorNode = (&theRootMatrix)->getRoot();

	//use the value of deeperX and deeperY axis to determine bounds of binding

	int x = 0;
	int y = 0;
	int z = 0;

	//for deeper axis. Might need to do this recursively tbqh.
	int dX = 0;
	int dY = 0;

	while (z != 1) { //might not be necessary

		while (y != yAxis) {

			while (x != xAxis) {
				cout << "[";
				//use similar logic as to the diagonal weave algorithm
				if (currentNode->getLeft() != nullptr && currentNode->getLeft()->getDeeper() != nullptr) {
					neighborNode = currentNode->getLeft();
					cout << "W:" << neighborNode->getData() << " ";
					bindSubNodes(currentNode, neighborNode, 0);
				} //west
				if (currentNode->getRight() != nullptr && currentNode->getRight()->getDeeper() != nullptr) {
					neighborNode = currentNode->getRight();
					cout << "E:" << neighborNode->getData() << " ";
					bindSubNodes(currentNode, neighborNode, 1);
				} //east
				if (currentNode->getUpper() != nullptr && currentNode->getUpper()->getDeeper() != nullptr) {
					neighborNode = currentNode->getUpper();
					cout << "N:" << neighborNode->getData() << " ";
					bindSubNodes(currentNode, neighborNode, 2);
				} //north
				if (currentNode->getLower() != nullptr && currentNode->getLower()->getDeeper() != nullptr) {
					neighborNode = currentNode->getLower();
					cout << "S:" << neighborNode->getData() << " ";
					bindSubNodes(currentNode, neighborNode, 3);
				} //south
				cout << "] ";
				if (currentNode->getRight() != nullptr) {
					currentNode = currentNode->getRight();
				}
				x++;
				if (x == xAxis / 2) {
					cout << endl;
				}
			}
			cout << endl;
			cout << endl;
			anchorNode = anchorNode->getLower();
			currentNode = anchorNode;
			neighborNode = anchorNode;
			x = 0;
			y++;
		}
		z++;
	}
	int count = 0; //set this equal to the square of rootmatrix size

}

void Matrix::bindSubNodes(matrixNode * primaryNode, matrixNode * secondaryNode, int cardinal) {

	matrixNode * primarySubNode = primaryNode->getDeeper();
	matrixNode * secondarySubNode = secondaryNode->getDeeper();

	if (cardinal == 0) {		//primaryNode West to secondaryNode East
		int i = 1;
		while (i != primaryNode->getDeeperXAxis()) {		//iterate secondary to East side
			i++;
			secondarySubNode = secondarySubNode->getRight();
		}
		i = 1;
		while (i != primaryNode->getDeeperXAxis()) {
			i++;
			primarySubNode->setLeft(secondarySubNode);
			secondarySubNode->setRight(primarySubNode);
			primarySubNode = primarySubNode->getLower();
			secondarySubNode = secondarySubNode->getLower();
		}
		//iterate both straight down
	}//west = 0
	if (cardinal == 1) {		//primaryNode East to secondaryNode West
		int i = 1;
		while (i != primaryNode->getDeeperXAxis()) {		//iterate primary to East side
			i++;
			primarySubNode = primarySubNode->getRight();
		}
		i = 0; //odd that we need i = 0 instead of 1 here. Check into it.
		while (i != primaryNode->getDeeperXAxis()) {
			i++;
			primarySubNode->setRight(secondarySubNode); //malformed, not an 8x8 matrix
			secondarySubNode->setLeft(primarySubNode);
			primarySubNode = primarySubNode->getLower();
			secondarySubNode = secondarySubNode->getLower();

		}
		//iterate both straight down
	}//east = 1
	if (cardinal == 2) { 		//primaryNode North to secondaryNode South
		int i = 1;
		while (i != primaryNode->getDeeperYAxis()) {		//iterate secondary to South side
			i++;
			secondarySubNode = secondarySubNode->getLower();
		}
		i = 1;
		while (i != primaryNode->getDeeperYAxis()) {
			i++;
			primarySubNode->setUpper(secondarySubNode);
			secondarySubNode->setLower(primarySubNode);
			primarySubNode = primarySubNode->getRight();
			secondarySubNode = secondarySubNode->getRight();
		}
		//iterate both straight across
	}//north = 2
	if (cardinal == 3) {		//primaryNode South to secondaryNode North
		int i = 1;
		while (i != primaryNode->getDeeperYAxis()) {		//iterate primary to South side
			i++;
			primarySubNode = primarySubNode->getLower();
		}
		i = 1;
		while (i != primaryNode->getDeeperYAxis()) {
			i++;
			primarySubNode->setLower(secondarySubNode);
			secondarySubNode->setUpper(primarySubNode);
			primarySubNode = primarySubNode->getRight();
			secondarySubNode = secondarySubNode->getRight();
		}
		//iterate both straight across
	}//south = 3

}

//Used to Bind two Matrices with a depth of 1 together. Useful for spot fusing when you shouldn't have to write add'l logic.
void Matrix::bindShallowNodes(Matrix * primaryNode, Matrix * secondaryNode, int cardinal) {

	matrixNode * primarySubNode = primaryNode->getRoot();
	matrixNode * secondarySubNode = secondaryNode->getRoot();

	if (cardinal == 0) {		//primaryNode West to secondaryNode East
		int i = 1;
		while (i != primaryNode->getMatrixXAxis()) {		//iterate secondary to East side
			i++;
			secondarySubNode = secondarySubNode->getRight();
		}
		i = 1;
		while (i != primaryNode->getMatrixXAxis()) {
			i++;
			primarySubNode->setLeft(secondarySubNode);
			secondarySubNode->setRight(primarySubNode);
			primarySubNode = primarySubNode->getLower();
			secondarySubNode = secondarySubNode->getLower();
		}
		//iterate both straight down
	}//west = 0
	if (cardinal == 1) {		//primaryNode East to secondaryNode West
		int i = 1;
		while (i != primaryNode->getMatrixXAxis()) {		//iterate primary to East side
			i++;
			primarySubNode = primarySubNode->getRight();
		}
		i = 0; //odd that we need i = 0 instead of 1 here. Check into it.
		while (i != primaryNode->getMatrixXAxis()) {

			i++;
			primarySubNode->setRight(secondarySubNode); //malformed, not an 8x8 matrix
			secondarySubNode->setLeft(primarySubNode);
			primarySubNode = primarySubNode->getLower();
			secondarySubNode = secondarySubNode->getLower();

		}
		//iterate both straight down
	}//east = 1
	if (cardinal == 2) { 		//primaryNode North to secondaryNode South
		int i = 1;
		while (i != primaryNode->getMatrixYAxis()) {		//iterate secondary to South side
			i++;
			secondarySubNode = secondarySubNode->getLower();
		}
		i = 1;
		while (i != primaryNode->getMatrixYAxis()) {
			i++;
			primarySubNode->setUpper(secondarySubNode);
			secondarySubNode->setLower(primarySubNode);
			primarySubNode = primarySubNode->getRight();
			secondarySubNode = secondarySubNode->getRight();
		}
		//iterate both straight across
	}//north = 2
	if (cardinal == 3) {		//primaryNode South to secondaryNode North
		int i = 1;
		while (i != primaryNode->getMatrixYAxis()) {		//iterate primary to South side
			i++;
			primarySubNode = primarySubNode->getLower();
		}
		i = 1;
		while (i != primaryNode->getMatrixYAxis()) {
			i++;
			primarySubNode->setLower(secondarySubNode);
			secondarySubNode->setUpper(primarySubNode);
			primarySubNode = primarySubNode->getRight();
			secondarySubNode = secondarySubNode->getRight();
		}
		//iterate both straight across
	}//south = 3

	 //used to move root of the new merged matrix to the actual root. (Might be able to use getRoot()?)
	while ((*secondaryNode).getRoot() != nullptr) {
		(*secondaryNode).setRoot((*secondaryNode).getRoot()->getLeft());
	}

}


void Matrix::nodeTraverse(matrixNode * target) {

	matrixNode * delve = target;
	matrixNode * delveAnchor = target;

	if (delve->getDeeper() != nullptr) {
		delve = delve->getDeeper();
		delveAnchor = delveAnchor->getDeeper();
	}

	while (delveAnchor != nullptr) {
		cout << "New Row: " << endl;
		cout << delveAnchor->getDeeperData() << " ";
		while (delve->getRight() != nullptr) {
			delve = delve->getRight();
			cout << delve->getDeeperData() << " ";
		}
		delveAnchor = delveAnchor->getLower();
		delve = delveAnchor;
		cout << endl;
		cout << endl;
	}


}
void Matrix::metaTraverse() {

}

/*  ACTUAL RANDOM NUMBER GENERATOR O_O
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
int i,j;

// set the seed
srand( (unsigned)time( NULL ) );

generate 10  random numbers.
for (i = 0; i < 10; i++) {
// generate actual random number
j = rand();
cout << " Random Number : " << j << endl;
}

return 0;
}

*/