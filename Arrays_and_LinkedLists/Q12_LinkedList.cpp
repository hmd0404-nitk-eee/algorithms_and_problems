/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program implements the peval(a, x) as mentioned where a is Linked List and x is a real number.

This program includes two header files LinkedList and Node for basic assistance.
*/

#include <iostream>
#include <math.h>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

void peval(class LinkedList *a, float x);
void pread(class LinkedList *x);

int main() {
	LinkedList *a = new LinkedList();
	float x;
	
	cout << "This program implements the peval(a, x) as mentioned where a is Linked List and x is a real number." << endl;
	cout << "This program includes two header files LinkedList and Node for basic assistance." << endl;
	
	pread(a);
	cout << "\nEnter the value of x: ";
	cin >> x;
	peval(a, x);
	
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
	x->printPoly();
	
	return;
}

void peval(class LinkedList *a, float x) {
	float sum = 0;
	node* ptr;
	ptr = a->getHead();
	
	do {
		sum += ptr->getCoeff() * pow(x, ptr->getPower());
		ptr = ptr->getNextNode();
	} while(ptr != a->getHead());
	
	cout << "The value of polynomial a at x = " << x << " is " << sum << endl;
	return;
}
