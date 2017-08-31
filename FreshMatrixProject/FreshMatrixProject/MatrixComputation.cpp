#include "MatrixComputation.h"

MatrixComputation::MatrixComputation() {

}
MatrixComputation::~MatrixComputation() {

}

/*When receiving values the xAxis has to equal the yAxis if multiplying matrices
*/
Matrix * MatrixComputation::multiplyProduct(matrixNode * left, matrixNode * right, int matrixXAxis, int matrixYAxis) {


	if (matrixXAxis != matrixYAxis) {
		//catch that mother fucker, they must be equal in order to produce a product
	}
	MatrixController * processControl = new MatrixController();

	Matrix * process = new Matrix();

	matrixNode * product = new matrixNode();

	int xSize = matrixXAxis;
	int ySize = matrixYAxis;

	processControl->setTheRoot(process);

	process->setRoot(product); //might not reflect changes made. 2x check for learning purposes.

	processControl->generateAMatrix((*process), matrixXAxis, matrixYAxis + 1); //watch this +1 for issues later

	process->diagonalWeave(*(product), matrixXAxis, matrixYAxis);

	process->printMatrix();

	return process;

}
Matrix * MatrixComputation::dotProduct(matrixNode * left, matrixNode * right, int matrixXAxis, int matrixYAxis) {
	Matrix * process = new Matrix();
	return process;
}
Matrix * MatrixComputation::crossProduct(matrixNode * left, matrixNode * right, int matrixYAxis, int matrixXAxis) {

	Matrix * placeHolder = new Matrix();

	return placeHolder;

}
Matrix * MatrixComputation::inverseMatrix(Matrix * invertThis) {

	MatrixController * theControl = new MatrixController;

	Matrix * determinantMatrix = theControl->makeDeterminant(invertThis->getMatrixXAxis(), invertThis->getMatrixXAxis());

	determinantMatrix->diagonalWeave(*(determinantMatrix->getRoot()), determinantMatrix->getMatrixXAxis(), determinantMatrix->getMatrixYAxis());

	determinantMatrix->bindShallowNodes(invertThis, determinantMatrix, 1);

	theControl->divideTargetRow(*invertThis, 0);

	return invertThis;

}