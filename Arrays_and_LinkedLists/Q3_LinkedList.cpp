/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This programs inputs two linked lists of sizes m and n.
And merges the two lists as per the rule:
a. if m <= n : (x1, y1, ........, xm, ym, xm+1, xm+2,....., xn)
b. if m > n : (x1, y1,.........., xn, yn, yn+1, yn+2,....., ym)

This program includes two header files LinkedList and Node for basic assistance
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

int main () {
	LinkedList list1, list2, finalList;
	int m, n, dataTemp;
	
	cout << "This programs inputs two linked lists of sizes m and n." << endl;
	cout << "And merges the two lists as per the rule:" << endl;
	cout << "a. if m <= n : (x1, y1, ........, xm, ym, xm+1, xm+2,....., xn)" << endl;
	cout << "b. if m > n : (x1, y1,.........., xn, yn, yn+1, yn+2,....., ym)" << endl;
	cout << endl << endl << "This program includes two header files LinkedList and Node for basic assistance" << endl;
	
	//Inputting lists
	cout << endl << "Enter the data for the list1 (enter E to terminate): ";
	while(cin >> dataTemp) {
		list1.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	list1.printList();
	
	cout << endl << "Enter the data for the list2 (enter E to terminate): ";
	while(cin >> dataTemp) {
		list2.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	list2.printList();
	
	//Merging lists
	m = list1.getLength();
	n = list2.getLength();
	node *ptr1, *ptr2; 
	ptr1 = list1.getHead();
	ptr2 = list2.getHead();
	
	while(ptr1 != NULL && ptr2 != NULL) {
		finalList.pushData(ptr1->getData());
		finalList.pushData(ptr2->getData());
		ptr1 = ptr1->getNextNode();
		ptr2 = ptr2->getNextNode();
	}
	
	while(ptr1 != NULL) {
		finalList.pushData(ptr1->getData());
		ptr1 = ptr1->getNextNode();
	}
	
	while(ptr2 != NULL) {
		finalList.pushData(ptr2->getData());
		ptr2 = ptr2->getNextNode();
	}
	
	cout << endl;
	finalList.printList();
	
	return 0;
}
