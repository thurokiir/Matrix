#include "MatrixController.h"

using std::vector;


MatrixController::MatrixController() {

}

MatrixController::MatrixController(const int * arrayOfInts, const int & arrayOfIntsSize) { //const for array of ints not necessary?

	testArray = arrayOfInts;//saving the address
	testArraySize = arrayOfIntsSize;
	matrixDimension = arrayOfIntsSize;
	tempMatrixArray = new int[testArraySize];

	for (int i = 0; i < testArraySize; i++) {
		tempMatrixArray[i] = testArray[i];
	}
}

MatrixController::MatrixController(const int * arrayOfNumbers, const int & xAxis, const int & yAxis) {

	testArray = arrayOfNumbers;
	testArraySize = xAxis * yAxis;
	matrixXAxis = xAxis;
	matrixYAxis = yAxis;
	tempMatrixArray = new int[testArraySize];

	for (int i = 0; i < testArraySize; i++) {
		tempMatrixArray[i] = testArray[i];
	}

}


//}
//Matrix * MatrixController::generateAMatrix() {
//
//	matrixNode * temp = new matrixNode();
//	matrixNode * storage;
//	int track = 0;
//	while (track != matrixDimension) {
//
//		if (temp == nullptr) {
//			temp = proxyMatrix->makeARow(formatTheArrayOfInts(tempMatrixArray, (matrixDimension * track), testArraySize), matrixDimension);
//
//		}
//		else {
//			temp = proxyMatrix->makeARow(formatTheArrayOfInts(tempMatrixArray, (matrixDimension * track), testArraySize), matrixDimension);
//		}
//
//		if (proxyMatrix->getRoot()->getUpper() != nullptr) { //check if this is causing us issues. 3/3
//			temp->getUpper()->setUpper(proxyMatrix->getRoot()->getUpper());
//		} 
//		proxyMatrix->setRoot(temp);
//		track++;
//
//	}
//
//	moveTheRoot();
//	weave();
//	//printTheMatrix();
//
//	return proxyMatrix;
//}

Matrix * MatrixController::generateAPictureMatrix() {


	Mat image;

	image = imread("LightsAllNight.jpg", IMREAD_COLOR); // Read the file

	if (image.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}

	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.

	//imshow("Display window", image); // Show our image inside it.

	//waitKey();

	Size testSize = image.size();

	int yTrack = 0;
	int xTrack = 0;
	int xCoord = 0;
	int yCoord = 0;

	matrixNode * storage;
	matrixNode * temp = new matrixNode();
	matrixNode * xAxisIterate = new matrixNode();
	matrixNode * yAxisIterate = new matrixNode();
	int xAxisHolder = 0;
	yAxisIterate->setColors(image.at<Vec3b>(yTrack, xTrack).val[0], image.at<Vec3b>(yTrack, xTrack).val[1], image.at<Vec3b>(yTrack, xTrack).val[2]);
	proxyMatrix->setRoot(yAxisIterate);
	proxyMatrix->setMatrixXAxis(testSize.width);
	proxyMatrix->setMatrixYAxis(testSize.height);
	xAxisHolder = testSize.width;

	xTrack++;



	while (yTrack != (testSize.height-1)) {

		yAxisIterate->setxAxis(0);
		yAxisIterate->setyAxis(yTrack);

		while (xTrack != (testSize.width-1)) {

			xAxisIterate = new matrixNode();

			xAxisIterate->setLeft(yAxisIterate);
			yAxisIterate->setRight(xAxisIterate);
			xAxisIterate->setColors(image.at<Vec3b>(yTrack, xTrack).val[0], image.at<Vec3b>(yTrack, xTrack).val[1], image.at<Vec3b>(yTrack, xTrack).val[2]);
			xAxisIterate->setxAxis(xTrack);
			xAxisIterate->setyAxis(yTrack);
			yAxisIterate = yAxisIterate->getRight();


			xTrack++;


		}

		while (yAxisIterate->getLeft() != nullptr) {
			yAxisIterate = yAxisIterate->getLeft();
		}

		yTrack++;
		temp = new matrixNode();
		temp->setColors(image.at<Vec3b>(yTrack, xTrack).val[0], image.at<Vec3b>(yTrack, xTrack).val[1], image.at<Vec3b>(yTrack, xTrack).val[2]);
		temp->setUpper(yAxisIterate);
		if (yTrack != matrixYAxis) {
			yAxisIterate->setLower(temp);
		}
		yAxisIterate = yAxisIterate->getLower();
		matrixXAxis = yAxisIterate->getxAxis();

		xTrack = 0;
	}



	weaveAPicture();

	matrixNode * diagonalNode = proxyMatrix->getRoot();

	proxyMatrix->diagonalWeave((*diagonalNode), testSize.width-1, testSize.height-1);

	return proxyMatrix;
}
//generates a matrix from the array passed to the Matrix Controller Constructor
Matrix * MatrixController::generateAMatrix() {

	int yTrack = 0;
	int xTrack = 0;

	matrixNode * storage;
	matrixNode * temp = new matrixNode();
	matrixNode * xAxisIterate = new matrixNode();
	matrixNode * yAxisIterate = new matrixNode();
	int xAxisHolder = 0;
	yAxisIterate->setData(testArray[xTrack]);
	proxyMatrix->setRoot(yAxisIterate);
	proxyMatrix->setMatrixXAxis(matrixXAxis);
	proxyMatrix->setMatrixYAxis(matrixYAxis);
	xAxisHolder = matrixXAxis;
	xTrack++;

	while (yTrack != matrixYAxis) {

		yAxisIterate->setxAxis(0);
		yAxisIterate->setyAxis(yTrack);

		while (xTrack != matrixXAxis) {

			xAxisIterate = new matrixNode();
			xAxisIterate->setLeft(yAxisIterate);
			yAxisIterate->setRight(xAxisIterate);
			xAxisIterate->setData(testArray[xTrack]);
			xAxisIterate->setxAxis(xTrack - (xAxisHolder*yTrack));
			xAxisIterate->setyAxis(yTrack);
			yAxisIterate = yAxisIterate->getRight();

			xTrack++;

		}
		while (yAxisIterate->getLeft() != nullptr) {
			yAxisIterate = yAxisIterate->getLeft();
		}
		yTrack++;
		temp = new matrixNode();
		temp->setData(testArray[xTrack]);
		temp->setUpper(yAxisIterate);
		if (yTrack != matrixYAxis) {
			yAxisIterate->setLower(temp);
		}
		yAxisIterate = yAxisIterate->getLower();
		matrixXAxis += xAxisHolder;
		xTrack++;
	}



	weave();

	
	return proxyMatrix;
}

void MatrixController::generateAMatrix(Matrix & computation, int xAxis, int yAxis) { //experiment! See if no pointer return works! =D

	int yTrack = 0;
	int xTrack = 0;

	matrixNode * storage;
	matrixNode * temp = new matrixNode();
	matrixNode * xAxisIterate = new matrixNode();
	matrixNode * yAxisIterate = new matrixNode();

	int xAxisHolder = 0;

	yAxisIterate->setData(0);
	yAxisIterate = computation.getRoot();
	computation.setMatrixXAxis(xAxis);
	computation.setMatrixYAxis(xAxis);
	xAxisHolder = xAxis;
	xTrack++;

	while (yTrack != yAxis) {
		yAxisIterate->setxAxis(0);
		yAxisIterate->setyAxis(yTrack);


		while (xTrack != xAxis) {

			xAxisIterate = new matrixNode();
			xAxisIterate->setLeft(yAxisIterate);
			yAxisIterate->setRight(xAxisIterate);
			xAxisIterate->setData(0.0);
			yAxisIterate = yAxisIterate->getRight();
			xAxisIterate->setxAxis(xTrack);
			xAxisIterate->setyAxis(yTrack);

			xTrack++;

		}
		while (yAxisIterate->getLeft() != nullptr) {
			yAxisIterate = yAxisIterate->getLeft();
		}
		yTrack++;
		temp = new matrixNode();
		temp->setData(xTrack);
		temp->setUpper(yAxisIterate);
		if (yTrack != yAxis) {
			yAxisIterate->setLower(temp);
		}
		yAxisIterate = yAxisIterate->getLower();
		xAxis += xAxisHolder;
		xTrack++;
	}



	weave();

}


//arrayOfInts parameter currently not necessary. Might need it for magnutides larger data sets
int * MatrixController::formatTheArrayOfInts(const int * arrayOfInts, const int & chopNumber, const int & index) {
	int * tempArray = new int[testArraySize];
	for (int i = 0; i < index; i++) { //Deep Copies The Array Given
		tempArray[i] = testArray[chopNumber + i];
	}
	return tempArray;
}

void MatrixController::moveTheRoot() {
	int i = 0;
	matrixNode * track = new matrixNode();
	matrixNode * terminous = new matrixNode();
	proxyMatrix->setRoot(proxyMatrix->getRoot()->getUpper());
	proxyMatrix->getRoot()->setLower(terminous);
	track = proxyMatrix->getRoot();
	while (i != testArraySize - 1) {  //rewrite this to use track, that way we can reset root from any y position
		proxyMatrix->setRoot(proxyMatrix->getRoot()->getUpper());
		proxyMatrix->getRoot()->setLower(track);
		//cout << "Current Proxy Matrix rootData value: " << proxyMatrix->getRoot()->getData() << endl;
		track = proxyMatrix->getRoot();
		i++;
	}
}

void MatrixController::weave() {
	int i = 0;
	matrixNode * top = new matrixNode();
	top = proxyMatrix->getRoot();
	matrixNode * bottom = new matrixNode();
	bottom = proxyMatrix->getRoot()->getLower();
	matrixNode * topY = new matrixNode();
	topY = top;
	matrixNode * bottomY = new matrixNode();
	bottomY = bottom;



	while (bottom != nullptr) { //move down

		while (top != nullptr) { //move across
			top->setLower(bottom);
			bottom->setUpper(top);
			top = top->getRight();
			bottom = bottom->getRight();

		}
		top = topY->getLower();
		bottom = bottomY->getLower();
		topY = top;
		bottomY = bottom;

	}
}
void MatrixController::weaveAPicture() {
	int i = 0;
	matrixNode * top = new matrixNode();
	top = proxyMatrix->getRoot();
	matrixNode * bottom = new matrixNode();
	bottom = proxyMatrix->getRoot()->getLower();
	matrixNode * topY = new matrixNode();
	topY = top;
	matrixNode * bottomY = new matrixNode();
	bottomY = bottom;



	while (bottom->getLower() != nullptr) { //move down

		while (top != nullptr) { //move across
			top->setLower(bottom);
			bottom->setUpper(top);
			top = top->getRight();
			bottom = bottom->getRight();

		}
		top = topY->getLower();
		bottom = bottomY->getLower();
		topY = top;
		bottomY = bottom;

	}
}

Matrix * MatrixController::weave(Matrix * weaveThisMatrix) {
	int i = 0;
	matrixNode * top = new matrixNode();
	top = weaveThisMatrix->getRoot();
	matrixNode * bottom = new matrixNode();
	bottom = weaveThisMatrix->getRoot()->getLower();
	matrixNode * topY = new matrixNode();
	topY = top;
	matrixNode * bottomY = new matrixNode();
	bottomY = bottom;



	while (bottom != nullptr) { //move down

		while (top != nullptr) { //move across
			top->setLower(bottom);
			bottom->setUpper(top);
			top = top->getRight();
			bottom = bottom->getRight();

		}
		top = topY->getLower();
		bottom = bottomY->getLower();
		topY = top;
		bottomY = bottom;

	}

	return weaveThisMatrix;
}

void MatrixController::generateADeepMatrix(Matrix & theShallowMatrix, int sizeX, int sizeY, int xAxis, int yAxis) {

	matrixNode * matrixControllerNodeTest;
	matrixControllerNodeTest = theShallowMatrix.getRoot();

	matrixNode * matrixControllerNodeAnchor;
	matrixControllerNodeAnchor = theShallowMatrix.getRoot();


	int trackX = 0;
	int trackY = 0;

	int depth = theShallowMatrix.getDepthCount();
	depth++;
	theShallowMatrix.setDepthCount(depth);

	while (trackY != yAxis) {
		while (trackX != xAxis) {

			theShallowMatrix.goDeeperConventional(*matrixControllerNodeTest, theShallowMatrix.getMatrixXAxis(), theShallowMatrix.getMatrixYAxis(), sizeX, sizeY);
			theShallowMatrix.getRoot()->getDeeper()->setLowerRight(theShallowMatrix.getRoot()->getDeeper()->getLower()->getRight());
			matrixControllerNodeTest->setxAxis(trackX);
			matrixControllerNodeTest->setyAxis(trackY);
			matrixControllerNodeTest->setDeeperXAxis(sizeX);
			matrixControllerNodeTest->setDeeperYAxis(sizeY);
			matrixControllerNodeTest = matrixControllerNodeTest->getRight();
			trackX++;
		}
		trackX = 0;
		matrixControllerNodeAnchor = matrixControllerNodeAnchor->getLower();
		matrixControllerNodeTest = matrixControllerNodeAnchor;
		trackY++;
	}

	matrixControllerNodeTest = theShallowMatrix.getRoot();
	matrixControllerNodeAnchor = theShallowMatrix.getRoot();

	matrixNode * errorTest = theShallowMatrix.getRoot()->getDeeper();

	theShallowMatrix.diagonalWeave((*errorTest), sizeX, sizeY);

	trackX = 0;
	trackY = 0;
	int hold = 0;

	//This is for deepening matrices multiple times
	/*while (trackY != sizeY) {
	while (trackX != sizeX) {

	theShallowMatrix.diagonalWeave((*errorTest), sizeX, sizeY);
	matrixControllerNodeTest = matrixControllerNodeTest->getRight();
	errorTest = matrixControllerNodeTest->getDeeper();
	trackX++;

	}

	trackX = 0;
	matrixControllerNodeAnchor = matrixControllerNodeAnchor->getLower();
	matrixControllerNodeTest = matrixControllerNodeAnchor;
	errorTest = matrixControllerNodeTest->getDeeper();
	trackY++;
	}*/
}

Matrix * MatrixController::makeDeterminant(int xAxis, int yAxis) {

	Matrix * newDeterminant = new Matrix;


	int yTrack = 0;
	int xTrack = 0;

	matrixNode * storage;
	matrixNode * temp = new matrixNode();
	matrixNode * xAxisIterate = new matrixNode();
	matrixNode * yAxisIterate = new matrixNode();
	int xAxisHolder = 0;
	newDeterminant->setRoot(yAxisIterate);
	newDeterminant->setMatrixXAxis(xAxis);
	newDeterminant->setMatrixYAxis(yAxis);
	yAxisIterate->setData(1.0);
	xAxisHolder = xAxis;
	xTrack++;

	while (yTrack != yAxis) {

		yAxisIterate->setxAxis(0);
		yAxisIterate->setyAxis(yTrack);

		while (xTrack != xAxis) {

			xAxisIterate = new matrixNode();
			xAxisIterate->setLeft(yAxisIterate);
			yAxisIterate->setRight(xAxisIterate);

			if (xTrack == yTrack) {
				xAxisIterate->setData(1.0);
			}
			else {
				xAxisIterate->setData(0.0);
			}
			xAxisIterate->setxAxis(xTrack);
			xAxisIterate->setyAxis(yTrack);
			yAxisIterate = yAxisIterate->getRight();
			//			cout << xTrack << endl;
			xTrack++;

		}
		while (yAxisIterate->getLeft() != nullptr) {
			yAxisIterate = yAxisIterate->getLeft();
		}
		xTrack = 0;
		yTrack++;
		temp = new matrixNode();
		temp->setUpper(yAxisIterate);
		if (yTrack != yAxis) {
			yAxisIterate->setLower(temp);
		}
		yAxisIterate = yAxisIterate->getLower();
		matrixXAxis += xAxisHolder;
		xTrack++;
	}



	weave(newDeterminant);

	return newDeterminant;
}

void MatrixController::reworkAPicture() {

	Mat workIt(proxyMatrix->getMatrixYAxis(), proxyMatrix->getMatrixXAxis(), CV_8UC3, Scalar(0,0,0));

	int i = 0;
	int j = 0;

	matrixNode * xAxisIterate = proxyMatrix->getRoot();
	matrixNode * yAxisIterate = proxyMatrix->getRoot();
	

	while (i < (proxyMatrix->getMatrixYAxis()-1)) {

		while (j < (proxyMatrix->getMatrixXAxis()-1)) {

			workIt.at<Vec3b>(i, j).val[0] = (xAxisIterate->getRed());
			workIt.at<Vec3b>(i, j).val[1] = (xAxisIterate->getGreen());
			workIt.at<Vec3b>(i, j).val[2] = (xAxisIterate->getBlue());
			xAxisIterate = xAxisIterate->getRight();
			j++;
		}
		yAxisIterate = yAxisIterate->getLower();
		xAxisIterate = yAxisIterate;
		j = 0;
		i++;
	}
	

	thePictureMatrix = workIt;
}

Mat MatrixController::getThePicture() {
	return thePictureMatrix;
}

void MatrixController::skipOnce() {

	Mat workIt(proxyMatrix->getMatrixYAxis(), proxyMatrix->getMatrixXAxis(), CV_8UC3, Scalar(0, 0, 0));

	matrixNode * averageMe = proxyMatrix->getRoot();

	averageMe = averageMe->getLowerRight();

	matrixNode * xAxisIterate = averageMe;
	matrixNode * yAxisIterate = averageMe;

	int i = 1;
	int j = 1;

	while (yAxisIterate->getLower()->getLower() != nullptr) {

		while (xAxisIterate->getRight()->getRight() != nullptr) {

			workIt.at<Vec3b>(i, j).val[0] = (xAxisIterate->getRed());
			workIt.at<Vec3b>(i, j).val[1] = (xAxisIterate->getGreen());
			workIt.at<Vec3b>(i, j).val[2] = (xAxisIterate->getBlue());
			xAxisIterate = xAxisIterate->getRight()->getRight();
			j+=2;
		}
		yAxisIterate = yAxisIterate->getLower()->getLower();
		xAxisIterate = yAxisIterate;
		j = 0;
		i+=2;
	}
	imshow("Display window", workIt);
	waitKey(0);
}
void MatrixController::averageAPicture() {

	Mat workIt(proxyMatrix->getMatrixYAxis(), proxyMatrix->getMatrixXAxis(), CV_8UC3, Scalar(0, 0, 0));

	matrixNode * averageMe = proxyMatrix->getRoot();

	averageMe = averageMe->getLowerRight();

	matrixNode * xAxisIterate = averageMe;
	matrixNode * yAxisIterate = averageMe;

	int i = 1;
	int j = 1;

	while (yAxisIterate->getLower()->getLower() != nullptr) {

		while (xAxisIterate->getRight()->getRight() != nullptr) {

			int redAverage = 0;
			int greenAverage = 0;
			int blueAverage = 0;


			redAverage = (xAxisIterate->getLeft()->getRed()+
			xAxisIterate->getRight()->getRed()+
			xAxisIterate->getUpper()->getRed()+
			xAxisIterate->getLower()->getRed()+
			xAxisIterate->getUpperLeft()->getRed()+
			xAxisIterate->getUpperRight()->getRed()+
			xAxisIterate->getLowerLeft()->getRed()+
			xAxisIterate->getLowerRight()->getRed()+
			xAxisIterate->getRed())/3;

			greenAverage = (xAxisIterate->getLeft()->getGreen() +
				xAxisIterate->getRight()->getGreen() +
				xAxisIterate->getUpper()->getGreen() +
				xAxisIterate->getLower()->getGreen() +
				xAxisIterate->getUpperLeft()->getGreen() +
				xAxisIterate->getUpperRight()->getGreen() +
				xAxisIterate->getLowerLeft()->getGreen() +
				xAxisIterate->getLowerRight()->getGreen() +
				xAxisIterate->getGreen()) / 3;

			blueAverage = (xAxisIterate->getLeft()->getBlue() +
				xAxisIterate->getRight()->getBlue() +
				xAxisIterate->getUpper()->getBlue() +
				xAxisIterate->getLower()->getBlue() +
				xAxisIterate->getUpperLeft()->getBlue() +
				xAxisIterate->getUpperRight()->getBlue() +
				xAxisIterate->getLowerLeft()->getBlue() +
				xAxisIterate->getLowerRight()->getBlue() +
				xAxisIterate->getBlue()) / 3;

			xAxisIterate->setColors(redAverage, greenAverage, blueAverage);

			xAxisIterate = xAxisIterate->getRight()->getRight();
			j += 2;
		}
		yAxisIterate = yAxisIterate->getLower()->getLower();
		xAxisIterate = yAxisIterate;
		j = 0;
		i += 2;
	}


	i = 0;
	j = 0;

	xAxisIterate = proxyMatrix->getRoot();
	yAxisIterate = proxyMatrix->getRoot();


	while (i < (proxyMatrix->getMatrixYAxis() - 1)) {

		while (j < (proxyMatrix->getMatrixXAxis() - 1)) {

			workIt.at<Vec3b>(i, j).val[0] = (xAxisIterate->getRed());
			workIt.at<Vec3b>(i, j).val[1] = (xAxisIterate->getGreen());
			workIt.at<Vec3b>(i, j).val[2] = (xAxisIterate->getBlue());
			xAxisIterate = xAxisIterate->getRight();
			j++;
		}
		yAxisIterate = yAxisIterate->getLower();
		xAxisIterate = yAxisIterate;
		j = 0;
		i++;
	}


	imshow("Display window", workIt);
	waitKey(0);

	thePictureMatrix = workIt;
}

void MatrixController::smoothAPicture() {

	Mat workIt(proxyMatrix->getMatrixYAxis(), proxyMatrix->getMatrixXAxis(), CV_8UC3, Scalar(0, 0, 0));

	int i = 0;
	int j = 0;

	matrixNode * averageMe = proxyMatrix->getRoot();

	averageMe = averageMe->getLowerRight();
	
	matrixNode * yAxisIterate = averageMe;
	matrixNode * xAxisIterate = averageMe;

	while (yAxisIterate->getLower()->getLower() != nullptr) {

		while (xAxisIterate->getRight()->getRight() != nullptr) {

			int redAverage = 0;
			int greenAverage = 0;
			int blueAverage = 0;


			redAverage = (xAxisIterate->getLeft()->getRed() +
				xAxisIterate->getRight()->getRed() +
				xAxisIterate->getUpper()->getRed() +
				xAxisIterate->getLower()->getRed() +
				xAxisIterate->getUpperLeft()->getRed() +
				xAxisIterate->getUpperRight()->getRed() +
				xAxisIterate->getLowerLeft()->getRed() +
				xAxisIterate->getLowerRight()->getRed() +
				xAxisIterate->getRed()) / 9;

			greenAverage = (xAxisIterate->getLeft()->getGreen() +
				xAxisIterate->getRight()->getGreen() +
				xAxisIterate->getUpper()->getGreen() +
				xAxisIterate->getLower()->getGreen() +
				xAxisIterate->getUpperLeft()->getGreen() +
				xAxisIterate->getUpperRight()->getGreen() +
				xAxisIterate->getLowerLeft()->getGreen() +
				xAxisIterate->getLowerRight()->getGreen() +
				xAxisIterate->getGreen()) / 9;

			blueAverage = (xAxisIterate->getLeft()->getBlue() +
				xAxisIterate->getRight()->getBlue() +
				xAxisIterate->getUpper()->getBlue() +
				xAxisIterate->getLower()->getBlue() +
				xAxisIterate->getUpperLeft()->getBlue() +
				xAxisIterate->getUpperRight()->getBlue() +
				xAxisIterate->getLowerLeft()->getBlue() +
				xAxisIterate->getLowerRight()->getBlue() +
				xAxisIterate->getBlue()) / 9;

			xAxisIterate->setColors(redAverage, greenAverage, blueAverage);

			workIt.at<Vec3b>(i, j).val[0] = (xAxisIterate->getRed());
			workIt.at<Vec3b>(i, j).val[1] = (xAxisIterate->getGreen());
			workIt.at<Vec3b>(i, j).val[2] = (xAxisIterate->getBlue());
			xAxisIterate = xAxisIterate->getRight();
			j++;
		}
		yAxisIterate = yAxisIterate->getLower();
		xAxisIterate = yAxisIterate;
		j = 0;
		i++;
	}


	imshow("Display window", workIt);

	waitKey(0);

	thePictureMatrix = workIt;
}

void MatrixController::divideTargetRow(Matrix & invertingMatrix, int targetRow) {

	int numberOfRows = 1;
	int matrixSize = 1;
	int currentMatrixRow = 0;

	//double targetData = invertingMatrix.getRoot()->getData();

	double holderOne = 0.0;
	double holderTwo = 0.0;


	matrixNode * anchorFunctionNode = invertingMatrix.getRoot();
	matrixNode * currentRootNode = invertingMatrix.getRoot();

	matrixNode * xAxisFunctionNode = invertingMatrix.getRoot();
	matrixNode * xAxisRootNode = new matrixNode;

	while (currentRootNode != nullptr) { //moves the currentRootNode diagonally
		double targetData = currentRootNode->getData();
		anchorFunctionNode = currentRootNode;
		while (anchorFunctionNode->getUpper() != nullptr) {//places the anchor at the highest point over currentRootNode
			anchorFunctionNode = anchorFunctionNode->getUpper();
		}
		while (xAxisFunctionNode != nullptr) { //moves the xAxisFunctionNode Horizontally For Division.
			if (xAxisFunctionNode->getData() != 0.0000000000000) { //divides, does not subtract.
				xAxisFunctionNode->setData(xAxisFunctionNode->getData() / targetData);
				//				cout << xAxisFunctionNode->getData() << "  ";
			}
			xAxisFunctionNode = xAxisFunctionNode->getRight();
		}
		while (anchorFunctionNode != nullptr && (anchorFunctionNode->getData() != currentRootNode->getData())) { //moves anchorFunctionNode vertically
			anchorFunctionNode = anchorFunctionNode->getLower();
			xAxisFunctionNode = anchorFunctionNode; //resets the xAxisFunctionNode to the HomeRow.
													//use current rootNode as the Node to reference for subtraction.
			while (xAxisFunctionNode != nullptr) { //moves the xAxisFunctionNode Horizontally For Subtraction.
				xAxisRootNode = currentRootNode;
				cout << "(" << anchorFunctionNode->getxAxis() << "," << anchorFunctionNode->getyAxis() << ") ";
				xAxisFunctionNode->setData((xAxisFunctionNode->getData()) - (xAxisRootNode->getData()*anchorFunctionNode->getData()));
				//std::cout << std::showpoint << (xAxisFunctionNode->getData()) - (xAxisRootNode->getData()*anchorFunctionNode->getData()) << "  ";
				//cout << xAxisRootNode->getData()<< "  ";
				//cout << xAxisFunctionNode->getData() << "  ";
				//4/21/2017 issues with doubles and mathing changes to the nodes. Changes are happening. Just the wrong ones.
				xAxisFunctionNode = xAxisFunctionNode->getRight();
				xAxisRootNode = xAxisRootNode->getRight();
			}
			cout << endl;
			anchorFunctionNode = anchorFunctionNode->getLower();
		}

		currentRootNode = currentRootNode->getLowerRight();
	}
	proxyMatrix = &invertingMatrix;
	proxyMatrix->printMatrix();
}

void MatrixController::printTheMatrix() {
	proxyMatrix->printMatrix();
}

void MatrixController::setTheRoot(Matrix * newRoot) {
	proxyMatrix = newRoot;
}

Matrix * MatrixController::getTheRoot() {
	return proxyMatrix;
}