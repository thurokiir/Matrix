#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "matrixNode.h"
#include "Matrix.h"
#include "MatrixController.h"
#include "MatrixComputation.h"
#include "ImageMaker.h"

using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::stringstream;
using std::endl;
using std::vector;

using namespace cv;



int main(void) {

	int negativeTest = 0;
	int threeSquared = 0;
	int rootOfInput = 0;
	string prompt = "";
	/*int * arrayStorage = new int[9];*/
	int arrayStorageThree[9];
	int arrayStorageFour[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int randomStorageFour[] = { 13,8,3,10,5,3,16,7,14,10,1,9,13,6,15,2 };
	int arrayStorageEight[64];
	int arrayStorageEightByTwo[16];
	int arrayStorageVertical[] = { 1,2,3,4 };
	Mat * theImage;


	//stringstream myStream(prompt);
	//while (threeSquared != 9) {
	//	cout << "Please enter nine numbers: "; //Will expand to infinite once the program works.
	//	cin >> arrayStorageThree[threeSquared];
	//	//logic for catching invalid numbers (less than zero)
	//	if (myStream >> negativeTest) {
	//		break;
	//		cout << "Invalid number, please try again" << endl;
	//	}
	//	threeSquared++;
	//}

	//rootOfInput = sqrt(sizeof(arrayStorageThree) / sizeof*(arrayStorageThree));

	//MatrixController ignitionThree(arrayStorageThree,rootOfInput);

	//Matrix * testThree = new Matrix; 
	//
	//testThree = ignitionThree.generateAMatrix();

	//testThree->printMatrix();

	//for (int i = 0; i < sizeof(arrayStorageEight) / sizeof*(arrayStorageEight); i++) {
	//	arrayStorageEight[i] = i+1;
	//}

	//rootOfInput = sqrt(sizeof(arrayStorageEight) / sizeof*(arrayStorageEight));

	//MatrixController ignitionEight(arrayStorageEight, rootOfInput, rootOfInput);

	//Matrix * testEight;

	//testEight = ignitionEight.generateAMatrix();

	//testEight->printMatrix();

	////time to go deeper

	//testEight->goDeeperConventional(8,8);

	//ignitionEight.generateADeepMatrix(*testEight,8,8,8,8); //4096 little nodes all happy and talking to one another

	//testEight->diagonalWeave(*(testEight->getRoot()),rootOfInput,rootOfInput); //does the base matrix
	//																   
	//testEight->bindMetaNodes(*testEight , 8 , 8 );//might not need to call itself. Actually almost positive.
	//
	//testEight->nodeTraverse(testEight->getRoot());

	//for (int i = 0; i < sizeof(arrayStorageEightByTwo) / sizeof*(arrayStorageEightByTwo); i++) {
	//	arrayStorageEightByTwo[i] = i + 1;
	//}

	//int xAxis = 8;

	//int yAxis = 2;

	//MatrixController ignitionEightByTwo(arrayStorageEightByTwo, xAxis, yAxis);

	//Matrix * testEightByTwo;

	//testEightByTwo = ignitionEightByTwo.generateAMatrix();

	//testEightByTwo->printMatrix();

	//ignitionEightByTwo.generateADeepMatrix(*testEightByTwo,8,8,8,2);

	//testEightByTwo->diagonalWeave(*(testEightByTwo->getRoot()), xAxis, yAxis); //does the base matrix

	//testEightByTwo->bindMetaNodes(*testEightByTwo, xAxis, yAxis);

	//MatrixComputation * computeTest = new MatrixComputation();

	//MatrixController ignitionFour(randomStorageFour, 4, 4);

	//MatrixController ignitionHorizontal(arrayStorageVertical, 4, 1); //should delete and remake the constructor but i dont know how

	//MatrixController ignitionVertical(arrayStorageVertical, 1, 4);

	MatrixController pictureMatrix;

	pictureMatrix.generateAPictureMatrix();

	//pictureMatrix.reworkAPicture();

	//pictureMatrix.averageAPicture();
	//pictureMatrix.smoothAPicture();
	//pictureMatrix.averageAPicture();
	//pictureMatrix.smoothAPicture();
	//pictureMatrix.averageAPicture();
	//pictureMatrix.smoothAPicture();
	//pictureMatrix.averageAPicture();
	//pictureMatrix.smoothAPicture();
	//pictureMatrix.averageAPicture();
	//pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();
	pictureMatrix.smoothAPicture();

	

	imshow("Display window", pictureMatrix.getThePicture());

	waitKey();



	cout << "test" << endl;






	//Matrix * testFour = new Matrix;

	//Matrix * testFourByOne = new Matrix;

	//Matrix * testOneByFour = new Matrix;

	//Matrix * testCompute = new Matrix;

	//testFour = ignitionFour.generateAMatrix();

	//testFourByOne = ignitionHorizontal.generateAMatrix();

	//testOneByFour = ignitionVertical.generateAMatrix();

	//testFour->diagonalWeave(*(testFour->getRoot()),testFour->getMatrixXAxis(),testFour->getMatrixYAxis());

	//computeTest->inverseMatrix(testFour);



	//testCompute = computeTest->multiplyProduct(testFourByOne->getRoot(), testFour->getRoot(), testOneByFour->getMatrixYAxis(), testFourByOne->getMatrixXAxis());


	return 0;
}