/*
CS202 Assignment

Name: Harshal Dhake 191EE212

This program stores a lower triangular matrix efficiently (space wise).

The formula to map 2D indexing to 1D index .i.e. Matrix to Array is,
2D index (i,j) = (sigma(n){n from 1 to n-1} + j) in 1D indexing
*/

#include <iostream>
using namespace std;

#define MAXSIZE 100

//Evaluates the sigma
int sumTillNum(int num) {
	int sum = 0;
	for(int i = 0; i <= num; i++) {
		sum += i;
	}
	
	return sum;
}

int main() {
	int array[MAXSIZE], size, noOfElements;
	
	cout << "Enter the array size: ";
	cin >> size;
	
	/*if(size <= MAXSIZE) {
		array = new int[size];
	} else {
		array = NULL;
		cout << "Too big array!";
		return 0;
	}*/
	
	noOfElements = (size * (size+1)) / 2;
	cout << "Enter the lower triangular matrix in rows: ";
	for(int i = 0; i < noOfElements; i++) {
		cin >> array[i];
	}
	
	cout << "The addressing formula for mapping element a[i][j] in the lower triangle matrix stored by rows" << endl;
	cout << "in an array B[1....n(n+1)/2] with A[1][1] stored in B[1] is," << endl;
	cout << "Formula: To access element a[i][j], " << endl;
	cout << "  n = i-1  " << endl;
	cout << " --------- " << endl;
	cout << " \\         " << endl;
	cout << "  \\        " << endl;
	cout << "   \\       |-----       +    j     =  index of array" << endl;
	cout << "   /       |    |" << endl;
	cout << "  /        |    |" << endl;
	cout << " /         |    |" << endl;
	cout << " --------- " << endl;
	cout << "   n = 1   " << endl;
	
	cout << endl << "Using the above formula, the inputed matrix is: " << endl;
	
	int index = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(j > i) {
				cout << "0 ";
			} else {
				index = sumTillNum(i) + j;
				cout << array[index] << " ";
			}
		}
		cout << endl;
	}
	
	
	cout << "\nThe relation for zero part of A is i < j if i is row counter and j is column counter" << endl;
	return 0;
}
