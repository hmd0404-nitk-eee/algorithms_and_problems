/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program find the length of a given Linked List.
This program uses a function to count the length of linked list from the LinkedList.h header file and compares the its return
value with the intended value to check the correctness of the code
*/

#include <iostream>
#include "LinkedListImpl.h"

using namespace std;

int main()
{
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
	
	ll1.printList();

	lenByFunc = ll1.getLength();

	cout << endl;
	cout << "The length found by function is: " << lenByFunc << endl;

	//ll1.deleteLinkedList();

	return 0;
}
