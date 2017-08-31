#include "matrixNode.h"


matrixNode::~matrixNode() {

}
matrixNode::matrixNode() {
	leftEntry = nullptr;
	upperEntry = nullptr;
	rightEntry = nullptr;
	lowerEntry = nullptr;
	deeperEntry = nullptr; //might convert matrixNode deeper and higher to Matrix. We'll see.
	higherEntry = nullptr;

	upperLeftEntry = nullptr;
	upperRightEntry = nullptr;
	lowerLeftEntry = nullptr;
	lowerRightEntry = nullptr;

	data = 0.0;
	deeperData = 0.0;

	redInt = 0;
	greenInt = 0;
	blueInt = 0;


}
matrixNode * matrixNode::getRight() { //figure out what iteration cases require this and fix them so we can get rid of this
	if (this == nullptr) {
		return nullptr;
	}
	return rightEntry;
}
matrixNode * matrixNode::getUpper() { //figure out what iteration cases require this and fix them so we can get rid of this
	if (this == nullptr) {
		return nullptr;
	}
	return upperEntry;
}
matrixNode * matrixNode::getLeft() {
	return leftEntry;
}
matrixNode * matrixNode::getLower() {
	return lowerEntry;
}
matrixNode * matrixNode::getHigher() {
	return higherEntry;
}
matrixNode * matrixNode::getDeeper() {
	return deeperEntry;
}
matrixNode * matrixNode::getUpperLeft() {
	return upperLeftEntry;
}
matrixNode * matrixNode::getUpperRight() {
	return upperRightEntry;
}
matrixNode * matrixNode::getLowerLeft() {
	return lowerLeftEntry;
}
matrixNode * matrixNode::getLowerRight() {
	return lowerRightEntry;
}
double matrixNode::getData() {
	return data;
}
double * matrixNode::getDataAddress() {
	double * testPointer = &data;
	return testPointer;
}
double matrixNode::getDeeperData() {
	return deeperData;
}
int matrixNode::getRed() {
	return redInt;
}
int matrixNode::getGreen() {
	return greenInt;
}
int matrixNode::getBlue() {
	return blueInt;
}
int matrixNode::getxAxis() {
	return xAxis;
}
int matrixNode::getyAxis() {
	return yAxis;
}
int matrixNode::getDeeperXAxis() {
	return deeperXAxis;
}
int matrixNode::getDeeperYAxis() {
	return deeperYAxis;
}

void matrixNode::setUpper(matrixNode * newUpper) {
	this->upperEntry = newUpper;
}
void matrixNode::setLower(matrixNode * newLower) {
	this->lowerEntry = newLower;
}
void matrixNode::setLeft(matrixNode * newLeft) {
	this->leftEntry = newLeft;
}
void matrixNode::setRight(matrixNode * newRight) {
	this->rightEntry = newRight;
}
void matrixNode::setDeeper(matrixNode * newDeeper) {
	this->deeperEntry = newDeeper;
}
void matrixNode::setHigher(matrixNode * newHigher) {
	this->higherEntry = newHigher;
}
void matrixNode::setUpperLeft(matrixNode * newUpperLeft) {
	this->upperLeftEntry = newUpperLeft;
}
void matrixNode::setUpperRight(matrixNode * newUpperRight) {
	this->upperRightEntry = newUpperRight;
}
void matrixNode::setLowerLeft(matrixNode * newLowerLeft) {
	this->lowerLeftEntry = newLowerLeft;
}
void matrixNode::setLowerRight(matrixNode * newLowerRight) {
	this->lowerRightEntry = newLowerRight;
}
void matrixNode::setData(double newData) {
	this->data = newData;
}
void matrixNode::setColors(int red, int green, int blue) {
	this->redInt = red;
	this->greenInt = green;
	this->blueInt = blue;
}
void matrixNode::setDeeperData(double newDeepData) {
	this->deeperData = newDeepData;
}
void matrixNode::setxAxis(int xAxis) {
	this->xAxis = xAxis;
}
void matrixNode::setyAxis(int yAxis) {
	this->yAxis = yAxis;
}
void matrixNode::setDeeperXAxis(int deeperXaxis) {
	this->deeperXAxis = deeperXaxis;
}
void matrixNode::setDeeperYAxis(int deeperYAxis) {
	this->deeperYAxis = deeperYAxis;
}




matrixNode matrixNode::operator+(const matrixNode & other) {
	matrixNode temp;
	temp.data = this->data + other.data;
	return temp;
}
matrixNode matrixNode::operator-(const matrixNode & other) {
	matrixNode temp;
	temp.data = this->data - other.data;
	return temp;
}
matrixNode matrixNode::operator* (const matrixNode & other) {
	matrixNode temp;
	temp.data = this->data * other.data;
	return temp;
}
matrixNode matrixNode::operator/ (const matrixNode & other) {
	matrixNode temp;
	temp.data = this->data / other.data;
	return temp;
}
matrixNode matrixNode::operator% (const matrixNode & other) {
	matrixNode temp;
	temp.data = static_cast<int>(this->data) % static_cast<int>(other.data);
	return temp;
}

//example of how to use these. Note a lack of POINTERS.
//matrixNode firstTest;
//matrixNode secondTest;
//matrixNode thirdTest;
//firstTest.setData(5);
//secondTest.setData(9);
//thirdTest = firstTest + secondTest;
//firstTest + secondTest;
//cout << "addition test   " << thirdTest.getData() << endl;

//http://www.cprogramming.com/tutorial/operator_overloading.html

//example for input>> and output<<
//friend ostream &operator<<(ostream &out, Complex c)     //output
//{
//	out << "real part: " << c.real << "\n";
//	out << "imag part: " << c.imag << "\n";
//	return out;
//}
//friend istream &operator >> (istream &in, Complex &c)     //input
//{
//	cout << "enter real part:\n";
//	in >> c.real;
//	cout << "enter imag part: \n";
//	in >> c.imag;
//	return in;
//}


//possible different assignment using addresses method
//My_Array & operator= (const My_Array & other)
//{
//	if (this != &other) // protect against invalid self-assignment
//	{
//		// 1: allocate new memory and copy the elements
//		int * new_array = new int[other.count];
//		std::copy(other.array, other.array + other.count, new_array);
//
//		// 2: deallocate old memory
//		delete[] array;
//
//		// 3: assign the new memory to the object
//		array = new_array;
//		count = other.count;
//	}
//	// by convention, always return *this
//	return *this;
//}
//void swap(My_Array & other) // the swap member function (should never fail!)
//{
//	// swap all the members (and base subobject, if applicable) with other
//	using std::swap; // because of ADL the compiler will use 
//					 // custom swap for members if it exists
//					 // falling back to std::swap
//	swap(array, other.array);
//	swap(count, other.count);
//}
//
//My_Array & operator = (My_Array other) // note: argument passed by value!
//{
//	// swap this with other
//	swap(other);
//
//	// by convention, always return *this
//	return *this;
//
//	// other is destroyed, releasing the memory
//}


