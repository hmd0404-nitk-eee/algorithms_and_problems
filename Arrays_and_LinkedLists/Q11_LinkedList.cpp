/*
CS202 Assignment

Name: Harshal Dhake - 191EE212


This Program implement the multiplication of two polynomials

This program uses the pread(x) as mentioned as a circular linked list in Q10_LinkedList.
The parameter x is the reference to a Linked List and the function pread converts it into a circular list.
The function pread(x) inputs the polynomial as a pair of (ci, ei) === (coeff, power/exponent)

The algorithm requires O() time to multiply two polynomials and O(m+n) space complexity (worst case).
Here m and n are the lengths of the polynomials.

This program includes two header files LinkedList and Node for basic assistance.
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

//returns the maxPower of the polynomial
int pread(class LinkedList *x);
class LinkedList *multiplyPoly(class LinkedList *a, class LinkedList *b);


int main() {
	LinkedList *a = new LinkedList();
	LinkedList *b = new LinkedList();
	LinkedList *c = new LinkedList();
	int maxPowerA, maxPowerB;
	
	cout << "This Program implement the multiplication of two polynomials" << endl;
	cout << "This program uses the pread(x) as mentioned as a circular linked list in Q10_LinkedList." << endl;
	cout << "The parameter x is the reference to a Linked List and the function pread converts it into a circular list." << endl;
	cout << "The function pread(x) inputs the polynomial as a pair of (ci, ei) === (coeff, power/exponent)" << endl;
	cout << "The algorithm requires O() time to multiply two polynomials and O(m+n) space complexity (worst case)." << endl;
	cout << "Here m and n are the lengths of the polynomials." << endl;
	cout << "This program includes two header files LinkedList and Node for basic assistance." << endl;
	
	//Inputting List
	maxPowerA = pread(a);
	cout << endl;
	maxPowerB = pread(b);
	
	c = multiplyPoly(a, b);
	cout << "\nAfter multiplying the given polynomials, " << endl;
	c->printPoly(maxPowerA + maxPowerB);
	cout << endl;
	
	return 0;
}

int pread(class LinkedList *x) {
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
	x->printPoly(maxPower);
	cout << endl;
	
	return maxPower;
}

class LinkedList *multiplyPoly(class LinkedList *a, class LinkedList *b) {
	LinkedList *ans = new LinkedList();
	LinkedList *ansFinal = new LinkedList();
	node *ptr1 = a->getHead();
	node *ptr2 = b->getHead();
	
	float coeff;
	int power;
	
	//multiplying all terms irrespective of same powers.
	do{
		ptr2 = b->getHead();
		do {
			coeff = ptr1->getCoeff() * ptr2->getCoeff();
			power = ptr1->getPower() + ptr2->getPower();
			ans->pushTermInPoly(coeff, power);
			ptr2= ptr2->getNextNode();
		}while(ptr2 != b->getHead());
		ptr1 = ptr1->getNextNode();
	} while(ptr1 != a->getHead());
	ans->circularizeList();
	
	//combining similar terms
	node *ptr3 = ans->getHead();
	node *searchPtr;
	int searchPower;
	do {
		if(ptr3->getPower() != -1) {
			searchPower = ptr3->getPower();
			coeff = 0;
			searchPtr = ans->searchPowerInPoly(searchPower);
			while(searchPtr != NULL){
				coeff += searchPtr->getCoeff();
				searchPtr->setPower(-1);
				searchPtr = ans->searchPowerInPoly(searchPower);
			}
			if(coeff) {
				ansFinal->pushTermInPoly(coeff, searchPower);
			}
		}
		ptr3 = ptr3->getNextNode();
	} while(ptr3 != ans->getHead());
	ansFinal->circularizeList();
	
	return ansFinal;
}
