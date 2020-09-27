/*
CS202 Assignment

Name: Harshal Dhake - 191EE212

This implements the Deque using a Linked List.
Deque is a ADT which allows inserions and deletions at either ends.

--->(insert/delete head) <Linked List.........> (insert/delete head)<---
|																	   |
|																	   |

This program also uses LinkedList and Node header files for basic handling functions
*/

#include <iostream>
#include "LinkedListImpl.h"
#include "NodeImpl.h"

using namespace std;

void addToList(class LinkedList *list, bool atEnd = false);
void deleteFromList(class LinkedList *list, bool atEnd = false);

int main() {
	LinkedList list;
	float dataTemp;
	
	cout << "This implements the Deque using a Linked List." << endl;
	cout << "Deque is a ADT which allows inserions and deletions at either ends." << endl;

	cout << endl << "--->(insert/delete head) <Linked List.........> (insert/delete head)<---" << endl;
	cout << endl << "This program also uses LinkedList and Node header files for basic handling functions" << endl;
	
	//Inputting the list
	cout << endl << "Enter the data for the list1 (enter E to terminate): ";
	while(cin >> dataTemp) {
		list.pushData(dataTemp);
	}
	cin.clear();
	fflush(stdin);
	
	list.printList();
	
	//Option to user
	int option;
	cout << "Enter the correct option number <only number>\n1.Add at Start\n2.Add at End\n3.Delete at Start\n4.Delete at End\n5.Exit\n: ";
	while(true) {
		cin >> option;
		switch(option) {
			case 1:
				addToList(&list);
				list.printList();
				break;
			case 2:
				addToList(&list, true);
				list.printList();
				break;
			case 3:
				deleteFromList(&list);
				list.printList();
				break;
			case 4:
				deleteFromList(&list, true);
				list.printList();
				break;
			case 5:
				return 0;
			default:
				cout << "Invalid input! Retry!\nEnter a valid option: ";
		}
	}
}

void addToList(class LinkedList *list, bool atEnd) {
	float dataTemp;
	
	cout << "Enter the data of the Node to insert: ";
	cin >> dataTemp;
	if(!atEnd) {
		node *newNode = new node(dataTemp);
		newNode->setNextNode(list->getHead());
		list->setHead(newNode);
	} else {
		list->pushData(dataTemp);
	}
	
	return;
}

void deleteFromList(class LinkedList *list, bool atEnd) {
	if(list->getHead() != NULL) {
		if(!atEnd) {
			list->setHead(list->getHead()->getNextNode());
		} else {
			node *ptr = list->getHead();
		
			while(ptr->getNextNode()->getNextNode() != NULL) {
				ptr = ptr->getNextNode();
			}
		
			ptr->setNextNode(NULL);
		}
	}
	
	return;
}
