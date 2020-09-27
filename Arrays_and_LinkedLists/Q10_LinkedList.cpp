/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program implements the pread(x) as mentioned as a circular linked list.
The parameter x is the reference to a Linked List and the function converts it into a circular list.
The function pread(x) inputs the polynomial as a pair of (ci, ei) === (coeff, power/exponent)

This program includes two header files LinkedList and Node for basic assistance.
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

void pread(class LinkedList *x);

int main() {
	LinkedList *x = new LinkedList();
	
	cout << "This program implements the pread(x) as mentioned as a circular linked list." << endl;
	cout << "The parameter x is the reference to a Linked List and the function converts it into a circular list." << endl;
	cout << "The function pread(x) inputs the polynomial as a pair of (ci, ei) === (coeff, power/exponent)" << endl;
	cout << "This program includes two header files LinkedList and Node for basic assistance." << endl;
	
	cout << "\n\nEnter the polynomial (as pairs of coeff power), " << endl;
	pread(x);
	return 0;
}

void pread(class LinkedList *x) {
	float c;
	int e, maxPower;
	
	//Inputting List
	cout << endl << "Enter the degree of the polynomial: ";
	cin >> maxPower;
	do {
		cout << "Enter the exponent (enter a exponent less than 0 to terminate): ";
		cin >> e;
		if(e <= maxPower && e >= 0) {
			cout << "Enter the coefficient for x^" << e << " : ";
			cin >> c;
			x->pushTermInPoly(c, e);
		}
	} while(e <= maxPower && e >= 0);
	
	x->circularizeList();
	x->printPoly(true);
	cout << endl;
	x->printPoly();
	
	return;
}
