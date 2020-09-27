/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program find the length of a given Circular Linked List.
This program uses a function to count the length of linked list from the LinkedList.h header file and compares the its return
value with the intended value to check the correctness of the code
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

int main()
{
	node *ptr;
	LinkedList ll1;
	int lenByFunc;
	float dataTemp;

	cout << "This program finds the length of the entered linked list using a function and checks with the inputted value." << endl;
	
	cout << endl << "Enter the data for the list (enter E to terminate): ";
	while(cin >> dataTemp) {
		ll1.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	ll1.circularizeList();
	ll1.printList();
	
	ptr = ll1.getHead();
	lenByFunc = 0;
	do {
		ptr = ptr->getNextNode();
		lenByFunc++;
	} while(ptr != ll1.getHead());
	
	cout << endl;

	cout << endl;
	cout << "The length found by function is: " << lenByFunc << endl;

	return 0;
}
