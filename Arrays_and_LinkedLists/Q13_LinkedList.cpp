/*
CS202 Assignment 
Name: Harshal Dhake - 191EE212

The program implements the mmul(a, b, c) where a, b, c are sparse matrices and c = a*b

This program uses Linked List implementation of sparse matrices.
The progran inputs matrix by rows.
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

//Global Variables
	int sizeOfA_n, sizeOfA_m, sizeOfB_m, sizeOfB_p, noOfElems_rA, noOfElems_rB;

void mmul(class LinkedList *a, class LinkedList *b, class LinkedList *c);

int main() {
	LinkedList *a = new LinkedList();
	LinkedList *b = new LinkedList();
	LinkedList *c = new LinkedList();

	float dataTemp;
	int xpos, ypos;
	
	cout << "The program implements the mmul(a, b, c) where a, b, c are sparse matrices and c = a*b" << endl;
	cout << "This program uses Linked List implementation of sparse matrices." << endl;
	cout << "The progran inputs matrix by rows." << endl;
	
	cout << "Enter the size (n and m) of the Matrix A: ";
	cin >> sizeOfA_n >> sizeOfA_m;
	cout << "Enter the number of Non-Zero Elements in the Sparse Matrix A: ";
	cin >> noOfElems_rA;
	
	cout << "Enter the size (" << sizeOfA_m << " and p) of the Matrix B: ";
	cin >> sizeOfB_p;
	sizeOfB_m = sizeOfA_m;
	cout << "Enter the number of Non-Zero Elements in the Sparse Matrix B: ";
	cin >> noOfElems_rB;
	
	//inputing the matrices
	cout << "Input the Matrix A, " << endl;
	for(int i = 0; i < noOfElems_rA; i++) {
		cout << "Element " << i+1 << ": ";
		cin >> dataTemp;
		cout << "At position (0,0)(indexed): ";
		cin >> xpos >> ypos;
		a->pushElementInMatrix(dataTemp, xpos, ypos);
	}
	
	cout << "Input the Matrix B, " << endl;
	for(int i = 0; i < noOfElems_rB; i++) {
		cout << "Element " << i+1 << ": ";
		cin >> dataTemp;
		cout << "At position (0,0)(indexed): ";
		cin >> xpos >> ypos;
		b->pushElementInMatrix(dataTemp, xpos, ypos);
	}
	
	//Printing the final Matrices
	cout << "The inputed Matrices are: " << endl;
	cout << "\nA: " << endl;
	a->printMatrix(sizeOfA_n, sizeOfA_m);
	
	cout << "The inputed Matrices are: " << endl;
	cout << "\nB: " << endl;
	b->printMatrix(sizeOfB_m, sizeOfB_p);
	
	mmul(a, b, c);
	
	cout << "The Multiplied Matrix is: " << endl;
	cout << "\nC: " << endl;
	c->printMatrix(sizeOfA_n, sizeOfB_p);
	
	return 0;
}

void mmul(class LinkedList *a, class LinkedList *b, class LinkedList *c) {
	float sum; 
	node *aElem, *bElem; 
	int index;
	for(int i = 0; i < sizeOfA_n; i++) {
		for(int j = 0; j < sizeOfB_p; j++) {
			sum = 0;
			index = 0;
			while(index < sizeOfB_m) {
				aElem = a->searchElementInMatrix(i, index);
				bElem = b->searchElementInMatrix(index, j);
				
				if(aElem && bElem) {
					sum += (aElem->getData() * bElem->getData());
				}
				index++;
			}
			
			c->pushElementInMatrix(sum, i, j);
		}
	}
}
