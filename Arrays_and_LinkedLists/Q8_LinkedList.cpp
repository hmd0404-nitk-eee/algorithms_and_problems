/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program reverses the links of a circular linked list.
It achieves this with a space complexity of O(1).

This program includes two header files LinkedList and Node for basic assistance
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

int main () {
	LinkedList cirList;
	float dataTemp;
	
	cout << "This program reverses the links of a circular linked list." << endl;
	cout << "It achieves this with a space complexity of O(1)." << endl;
	cout << "\nThis program includes two header files LinkedList and Node for basic assistance" << endl;
	
	//Inputting List
	cout << endl << "Enter the data for the list (enter E to terminate): ";
	while(cin >> dataTemp) {
		cirList.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	cirList.circularizeList();
	cirList.printList();
	
	//Reversing the links
	cirList.unCircularizeList();
	node *current, *next, *prev;
	int coveredLen = 0;
	
	current = cirList.getHead();
	prev = NULL;
	next = cirList.getHead()->getNextNode();
	while(current != NULL) {
		current->setNextNode(prev);
		prev = current;
		current = next;
		if(next != NULL) {
			next = next->getNextNode();
		}
	}
	
	cirList.setHead(prev);
	cirList.circularizeList();
	
	cout << "After reversing,";
	cirList.printList();
	
	return 0;
}
