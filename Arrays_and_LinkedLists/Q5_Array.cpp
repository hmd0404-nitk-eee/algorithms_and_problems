/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program find the location of Saddle points in the given Matrix.
The program furthermore uses a linear complexity algorithm to find the largest and smallest integers.
*/

#include <iostream>
using namespace std;

//Returns the location of the respective Elements
int* smallestElemInRow(int **matrix, int size, int rowNo);
int* largestElemInCol(int **matrix, int size, int colNo);

int main() {
	int **matrix, size;
	
	cout << "This program find the location of Saddle points in the given Matrix." << endl;
	cout << "The program furthermore uses a linear complexity algorithm to find the largest and smallest integers." << endl;
	cout << endl << endl << "Enter the matrix size: ";
	cin >> size;
	
	if(size > 0) {
		matrix = new int*[size];	
		for(int i = 0; i < size; i++) {
			matrix[i] = new int[size];
		}
	} else {
		cout << "Invalid Input!" << endl;
		return 0;
	}
	
	
	if(matrix != NULL) {
		cout << "Enter the matrix: ";
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				cin >> matrix[i][j];
			}
		}
		
		//printing out the Matrix
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				cout << "    " << matrix[i][j] << " ";
			}
			cout << endl;
		}
		
		//finding out the saddle points
		int *loc1, *loc2;
		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				loc1 = smallestElemInRow(matrix, size, i);
				loc2 = largestElemInCol(matrix, size, j);
				
				if(loc1 == loc2) {
					cout << "Saddle Point at (" << i << ", " << j << ") : " << *loc1 << endl;
				}
			}
		}
		
		//deallocating the memory
		for(int i = 0; i < size; i++) {
			delete []matrix[i];
		}
		delete []matrix;
	} else {
		cout << "Invalid Input!" << endl;
		return 0;
	}
	
	return 0;
}

int* smallestElemInRow(int **matrix, int size, int rowNo) {
	//Linear Searcg for smallest
	int smallest, *loc;
	
	smallest = matrix[rowNo][0];
	loc = &matrix[rowNo][0];
	for(int i = 0; i < size; i++) {
		if(matrix[rowNo][i] < smallest) {
			loc = &matrix[rowNo][i];
			smallest = matrix[rowNo][i];
		}
	}
	
	return loc;
}

int* largestElemInCol(int **matrix, int size, int colNo) {
	//Linear Searcg for smallest
	int largest, *loc;
	
	largest = matrix[0][colNo];
	loc = &matrix[0][colNo];
	for(int i = 0; i < size; i++) {
		if(matrix[i][colNo] > largest) {
			loc = &matrix[i][colNo];
			largest = matrix[i][colNo];
		}
	}
	
	return loc;
}
