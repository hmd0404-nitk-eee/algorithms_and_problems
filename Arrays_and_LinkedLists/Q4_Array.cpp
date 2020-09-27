/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program uses an efficient way to store the Tridiagonal Sparse Matrix in a 1D Array.
It uses array indexing technique to obtain A[i,j] from the Array B[index]
*/

#include <iostream>
using namespace std;

int main () {
	int *matrix, size, noOfElems, **matrix2D;
	
	cout << "This program uses an efficient way to store the Tridiagonal Sparse Matrix in a 1D Array. " << endl;
	cout << "It uses array indexing technique to obtain A[i,j] from the Array B[index]" << endl;
	
	cout << "Enter the matrix size: ";
	cin >> size;
	
	noOfElems = size * 3 - 2;
	matrix = new int[noOfElems];
	
	if(matrix != NULL) {
		cout << "Enter the Tridiagonal Matrix Elements row wise: " << endl;
		for(int i = 0; i < noOfElems; i++) {
			cin >> matrix[i];
		}
		
		//allocating the 2D matrix
		matrix2D = new int*[size];
		for(int i = 0; i < size; i++) {
			matrix2D[i] = new int[size];
		}
		
		//setting the 2D array from the 1D array
		int index1D = 0;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				switch(i-j) {
					case 0:
					case 1:
					case -1:
						matrix2D[i][j] = matrix[index1D];
						index1D++;
						break;
					default:
						matrix2D[i][j] = 0;
				}
			}
		}
		
		cout << "The inputted Tridiagonal Matrix is: " << endl << endl;
		//printing out the 2D array
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				cout << "    " << matrix2D[i][j] << " ";
			}
			cout << endl;
		}
		
		
		//deallocating memory
		for(int i = 0; i < size; i++) {
			delete []matrix2D[i];
		}
		delete []matrix2D;
		delete []matrix;
	} else {
		cout << "Invalid Input! Either the input is too large or not valid. Please retry." << endl;
		return 0;
	}
	
	return 0;
}
