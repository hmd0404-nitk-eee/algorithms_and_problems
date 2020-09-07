/* 
CS202 - Assignment

Name: Harshal Dhake - 191EE212

This program stores two lower trianlge matrices in a single array where one matrix is stored in form of its transpose
*/

#include <iostream>
using namespace std;

#define MAXSIZE 100

//Evaluates the sigma like Q2_Array
int sumTillNum(int num) {
	int sum = 0;
	for(int i = 0; i <= num; i++) {
		sum += i;
	}
	
	return sum;
}

int main () {
	int matrix1[MAXSIZE] = {0}, matrix2[MAXSIZE] = {0}, finalMatrix[MAXSIZE*(MAXSIZE + 1)] = {0};
	int size, sizeFinal;
	int noOfElems, noOfElemsFinal;
	
	cout << "This program inputs two lower triangle matrices and stores them into a single array thus\n";
	cout << "if the sizes of matrices are n then the size of final matrix is n*(n+1) number of elements\n";
	
	cout << "\nEnter the size of matrices: ";
	cin >> size;
	cout << "Input the first Matrix - Please input only the lower triangle elements by rows: " << endl;
	
	noOfElems = size * (size + 1) / 2;
	for(int i = 0; i < noOfElems; i++) {
		cin >> matrix1[i];
	}
	
	cout << "Input the second Matrix - Please input only the lower triangle elements by rows: " << endl;
	
	noOfElems = size * (size + 1) / 2;
	for(int i = 0; i < noOfElems; i++) {
		cin >> matrix2[i];
	}
	
	sizeFinal = size + 1;
	
	//Main Logic to store matrix1 and 2 in finalMatrix
	int finalIndex, mat1Index = 0, mat2Index = 0;
	for(int i = 0; i < sizeFinal; i++) {
		for(int j = 0; j < sizeFinal; j++) {
			finalIndex = sizeFinal * (i) + j;
			
			if(i == j) {
				finalMatrix[finalIndex] = 0;
			} else if (i < j) {
				finalMatrix[finalIndex] = matrix2[mat2Index];
				mat2Index++;
			} else if(i > j){
				finalMatrix[finalIndex] = matrix1[mat1Index];
				mat1Index++;
			}
		}
	}
	
	//Printing the final matrix
	cout << endl << "The Final Matrix is: " << endl;
	
	int index = 0;
	for(int i = 0; i < sizeFinal; i++) {
		cout << "   ";
		for(int j = 0; j < sizeFinal; j++) {
			index = sizeFinal*i + j;
			cout << finalMatrix[index] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
