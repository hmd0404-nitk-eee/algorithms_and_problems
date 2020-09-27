/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This program shows a circular linked list as a queue.
A queue is ADT which follows the FIFO principle.
It allows insertion or deletion only at one end.

This program includes two header files LinkedList and Node for basic assistance
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

void addToList(class LinkedList *list);
void deleteFromList(class LinkedList *list);

int main() {
	LinkedList cirList;
	float dataTemp;
	
	cout << "This program shows a circular linked list as a queue." << endl;
	cout << "A queue is ADT which follows the FIFO principle." << endl;
	cout << "It allows insertion or deletion only at one end." << endl;
	cout << "THE VALUE OF P when QUEUE is EMPTY is NULL" << endl;
	cout << "\nThis program includes two header files LinkedList and Node for basic assistance" << endl;
	
	//Inputting List
	cout << "THE QUEUE IN THE PROGRAM BELOW HAS HEAD COINCIDENT WITH LIST HEAD\n";
	cout << endl << "Enter the data for the Queue (enter E to terminate): ";
	while(cin >> dataTemp) {
		cirList.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	cirList.circularizeList();
	cirList.printList();
	
	//Option to user
	int option;
	cout << "Enter the correct option number <only number>\n1.Add a Node\n2.Delete a Node\n3.Exit\n: ";
	while(true) {
		cin >> option;
		switch(option) {
			case 1:
				addToList(&cirList);
				cirList.printList();
				break;
			case 2:
				deleteFromList(&cirList);
				cirList.printList();
				break;
			case 3:
				return 0;
			default:
				cout << "Invalid input! Retry!\nEnter a valid option: ";
		}
	}
	
	return 0;
}

void addToList(class LinkedList *list) {
	node *ptr = list->getHead();
	float dataTemp;
	
	cout << "Enter the data of the Node to insert: ";
	cin >> dataTemp;
	node *newNode = new node(dataTemp);
	while (ptr->getNextNode() != list->getHead()) {
		ptr = ptr->getNextNode();
	}
	//ptr = ptr->getNextNode();
	ptr->setNextNode(newNode);
	newNode->setNextNode(list->getHead());
	
	return;
}

void deleteFromList(class LinkedList *list) {
	node *oldHead = list->getHead();
	if(list->getHead() != NULL) {
		list->setHead(list->getHead()->getNextNode());
	}
	
	//Updating the links of the list
	node *ptr = list->getHead();
	while(ptr->getNextNode() != oldHead) {
		ptr = ptr->getNextNode();
	}
	ptr->setNextNode(list->getHead());
	
	return;
}
