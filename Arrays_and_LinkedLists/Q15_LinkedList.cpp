/*
CS202 Assignment 

Name: Harshal Dhake - 191EE212

This program implements the mtrp(a, b) to compute b = a transpose.

The program also uses LinkedList header file for the basic functionality
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

void mtrp(class LinkedList* matA, class LinkedList* matB);

int main() {
	LinkedList matrixA, matrixB;
	float dataTemp;
	int xpos, ypos, len, size;
	
	cout << "This program implements the mtrp(a, b) to compute b = a transpose." << endl;
	cout << "The program also uses LinkedList header file for the basic functionality" << endl;
	
	cout << "Enter the size of the Sparse Matrix: ";
	cin >> size;
	cout << "Enter the number of Non-Zero Elements in the Sparse Matrix: ";
	cin >> len;
	
	for(int i = 0; i < len; i++) {
		cout << "Element " << i+1 << ": ";
		cin >> dataTemp;
		cout << "At position (0,0)(indexed): ";
		cin >> xpos >> ypos;
		matrixA.pushElementInMatrix(dataTemp, xpos, ypos);
	}
	
	mtrp(&matrixA, &matrixB);
	
	cout << "The original Matrix is: " << endl;
	matrixA.printMatrix(size, size);
	
	cout << "The Transpose Matrix is: " << endl;
	matrixB.printMatrix(size, size);
	
	return 0;
}

void mtrp(class LinkedList *matA, class LinkedList *matB) {
	node *ptr = matA->getHead();
	
	while(ptr != NULL) {
		//Gets the transpose of Non-zero elements;
		matB->pushElementInMatrix(ptr->getData(), ptr->getYpos(), ptr->getXpos());
		ptr = ptr->getNextNode();
	}
	
	return;
}
