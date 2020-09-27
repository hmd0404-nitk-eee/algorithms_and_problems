/*
CS202 Assignment 
Name: Harshal Dhake - 191EE212

This program uses Linked List implementation of sparse matrices.
The progran inputs matrix by rows.

The program outputs the matrix in form of triplets (i, j, aij)
*/

#include <iostream>
#include "LinkedListImpl.h"

using namespace std;

int main() {
	LinkedList matrix;
	int xpos, ypos, len, size;
	float dataTemp;
	
	cout << "This program uses Linked List implementation of sparse matrices." << endl;
	cout << "The progran inputs matrix by rows." << endl;
	cout << "\nThe program outputs the matrix in form of triplets (i, j, aij)" << endl;
	
	cout << "Enter the size of the Matrix: ";
	cin >> size;
	cout << "Enter the number of Non-Zero Elements in the Sparse Matrix: ";
	cin >> len;
	
	for(int i = 0; i < len; i++) {
		cout << "Element " << i+1 << ": ";
		cin >> dataTemp;
		cout << "At position (0,0)(indexed): ";
		cin >> xpos >> ypos;
		matrix.pushElementInMatrix(dataTemp, xpos, ypos);
	}

	matrix.printMatrixAsTriplets(size, true);
	
	return 0;
}
