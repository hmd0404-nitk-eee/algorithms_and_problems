/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program deletes the node pointed by a random pointer x in a linked list and if x = p
where p is the head of the linked list then p must be re-set to new first node.

This program also uses the LinkedList and Node Header Files for including basic operations.
*/

#include <iostream>
#include "NodeImpl.h"
#include "LinkedListImpl.h"

int main () {
	LinkedList list;
	int pos;
	float dataTemp;
	
	cout << "This program deletes the node pointed by a random pointer x in a linked list and if x = p" << endl;
	cout << "where p is the head of the linked list then p must be re-set to new first node." << endl;
	cout << endl << "This program also uses the LinkedList and Node Header Files for including basic operations." << endl;
	
	cout << endl << "Enter the data for the list (enter E to terminate): ";
	while(cin >> dataTemp) {
		list.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	list.printList();
	
	cout << "Enter any arbitrary position from the list (0 indexed) to delete: ";
	cin >> pos;
	
	if(list.deleteNodeAtPosition(pos)) {
		cout << "Node Deleted Successfully!" << endl;
		cout << "The current head is: " << list.getHead()->getData() << endl;
		list.printList();
	} else {
		cout << "Invalid Input!" << endl;
		return 0;
	}
	
	return 0;
}
