/*
CS202 Assignment 1

Name: Harshal Dhake - 191EE212

This is the header file for Handling Linked Lists in C++.
*/
#include <iostream>
#include <string>
#include <sstream>
#include "NodeImpl.h"
using namespace std;

#ifndef LinkedListImpl
#define LinkedListImpl

class LinkedList {
	public:
		LinkedList() {
			head = NULL;
			isCircular = false;
		}
		
		LinkedList(node* newHead) {
			head = newHead;
			isCircular = false;
		}
		
		//Basic Operations
		node* getHead() {
			return head;
		}
		
		void setHead(node* newNode) {
			head = newNode;
			return;
		}
			
		int getLength() {
			int len = 0;
			node *ptr;
			ptr = this->getHead();
		
			if(isCircular == false) {
				while(ptr != NULL) {
					len++;
					ptr = ptr->getNextNode();
				}
			} else {
				while(ptr->getNextNode() != this->getHead()) {
					len++;
					ptr = ptr->getNextNode();
				}
				
				len++; //Counting the last node which gets left out
			}
	
			return len;
		}

		//Linear serach operations
		node * searchElementInMatrix(int x, int y) {
			node *ptr = this->getHead();
			
			while(ptr != NULL) {
				if(ptr->getXpos() == x && ptr->getYpos() == y) {
					return ptr;
				}
				ptr= ptr->getNextNode();
			}
			
			return NULL;
		}

		node *searchPowerInPoly(int pow) {
			node *ptr = this->getHead();
			
			if(ptr != NULL) {
				do {
					if(ptr->getPower() == pow) {
						return ptr;
					}
					ptr= ptr->getNextNode();
				} while(ptr != this->getHead());
			}
			
			return NULL;
		}

		//Basic Push operation
		void pushData(float data) {
			node *newNode = new Node(data);
			node *ptr;
			
			ptr = this->getHead();
			
			if(ptr == NULL) {
				this->setHead(newNode);
			} else {
				while(ptr->getNextNode() != NULL) {
					ptr = ptr->getNextNode();
				}
				
				ptr->setNextNode(newNode);
			}
			
			return;
		}
		
		void pushTermInPoly(float coeff, int power) {
			node *newNode = new Node(coeff, power);
			node *ptr;
			
			ptr = this->getHead();
			
			if(ptr == NULL) {
				this->setHead(newNode);
			} else {
				while(ptr->getNextNode() != NULL) {
					ptr = ptr->getNextNode();
				}
				
				ptr->setNextNode(newNode);
			}
			
			return;
		}
		
		void pushElementInMatrix(float data, int i, int j) {
			node *newNode = new Node(data, i, j);
			node *ptr;
			
			ptr = this->getHead();
			
			if(ptr == NULL) {
				this->setHead(newNode);
			} else {
				while(ptr->getNextNode() != NULL) {
					ptr = ptr->getNextNode();
				}
				
				ptr->setNextNode(newNode);
			}
			
			return;
		}
		
		//Basic Delete Operation
		node *deleteNodeAtPosition(int pos) {
			node *ptr = this->getHead();
			int length = this->getLength();
			  
			if(pos < length) {
				for(int i = 0; i < pos-1; i++) {
					ptr = ptr->getNextNode();
				}
				
				if(isCircular == false) {
					if(pos == length - 1) {
						ptr->setNextNode(NULL);
					} else if(pos == 0) {
						this->setHead(ptr->getNextNode());
					} else {
						ptr->setNextNode(ptr->getNextNode()->getNextNode());
					}
				} else {
					this->unCircularizeList();
					if(pos == length - 1) {
						ptr->setNextNode(NULL);
					} else if(pos == 0) {
						this->setHead(ptr->getNextNode());
					} else {
						ptr->setNextNode(ptr->getNextNode()->getNextNode());
					}
					this->circularizeList();
				}
			} else {
				return NULL;
			}
		}

		//Assuming zero based indexing
		node* traverseToPositionFromStart(int pos) {
			int currentPos = 0;
			node* ptr = this->getHead();
	
			if(pos < this->getLength()) {
				while(currentPos != pos) {
					currentPos++;
					ptr = ptr->getNextNode();
				}
			} else {
				return NULL;
			}
	
			return ptr;
		}
		
		//Inserting Node at a position from the start
		void insertNodeAtPos(node* newNode, int pos) {
			node* ptr;
			ptr = this->getHead();
			int currentPos = 0;
			
			if(pos <= this->getLength()) {
				while(currentPos < pos) {
					ptr = ptr->getNextNode();
				}
			
				newNode->setNextNode(ptr->getNextNode());
				ptr->setNextNode(newNode);
			}
			
			return;
		}
		
		//Inputting the linked list of certain length
		void inputLinkedList(int len) {
			node* ptr;
			ptr = this->getHead();
			float tempData;
			node* newNode;
			
			for(int i = 0; i < len; i++) {
				cout << "Enter the data for Node " << i << ": ";
				cin >> tempData;
		
				newNode = new node(tempData);
				if(ptr != NULL) {
					ptr->setNextNode(newNode);
					ptr = newNode;
				} else {
					this->setHead(newNode);
					ptr = this->getHead();
				}
			}
			
			return;
		}
		
		//Printing the formatted list
		void printList() {
			node* ptr;
			ptr = this->getHead();
	
			cout << "The Linked List is: " << endl;
			if(isCircular == false) {
				while(ptr != NULL) {
					if(ptr->getNextNode() != NULL) {
						cout << ptr->getData() << " --> ";
					} else {
						cout << ptr->getData();
					}
					ptr = ptr->getNextNode();
				}
				cout << endl;
			} else {
				string list;
				stringstream stream;
				
				stream << "---> ";
				do {
					if(ptr->getNextNode() != this->getHead()) {
						stream << ptr->getData() << " --> ";
					} else {
						stream << ptr->getData();
					}
					ptr = ptr->getNextNode();
				} while(ptr != this->getHead());
				list = stream.str();
			
				cout << list << " ----" << endl;
				cout << "|";
				for(int i = 0; i < list.length()+3; i++) {
					cout << " ";
				}
				cout << "|" << endl;
				for(int i = 0; i < list.length()+5; i++) {
					cout << "-";
				}
			
				cout << endl;	
			}

			return;
		}
		
		void printMatrixAsTriplets(int size, bool inorder = false) {
			node* ptr;
			ptr = this->getHead();
	
			if(inorder) {
				for(int i = 0; i < size; i++) {
					for(int j = 0; j < size; j++) {
						ptr = this->searchElementInMatrix(i, j);
						if(ptr) {
							cout << "(" << ptr->getXpos() << ", " << ptr->getYpos() << ", " << ptr->getData() << ") " << endl;
						}
					}
				}
				
				cout << endl;
			} else {
				cout << "The Matrix is: " << endl;
				while(ptr != NULL) {
					cout << "(" << ptr->getXpos() << ", " << ptr->getYpos() << ", " << ptr->getData() << ") " << endl;
					ptr = ptr->getNextNode();
				}
				cout << endl;
			}
			
			return;	
		}
		
		void printMatrix(int sizeM, int sizeN) {
			node *ptr = this->getHead();
			
			for(int i = 0; i < sizeM; i++) {
				for(int j = 0; j < sizeN; j++) {
					ptr = this->searchElementInMatrix(i, j);
					if(ptr) {
						cout << "   " << ptr->getData() << " ";
					} else {
						cout << "   0 ";
					}
				}
				cout << endl;
			}
			
			return;
		}
		
		void printPoly(int maxPower, bool printCircular = false) {
			string list;
			stringstream stream;
			
			node* ptr;
			bool firstPower = true;
			
			if(!printCircular) {
				stream << "The Polynomial is: ";
				for(int i = maxPower; i >= 0; i--) {
					ptr = this->searchPowerInPoly(i);
					if(ptr != NULL) {
						if(firstPower) {
							stream << ptr->getCoeff() <<" * x^" << ptr->getPower() << " ";
							firstPower = false;	
						} else {
							if(ptr->getCoeff() > 0) {
								stream << "+ "<< ptr->getCoeff() <<" * x^" << ptr->getPower() << " ";
							} else {
								stream << "- " << -1*ptr->getCoeff() <<" * x^" << ptr->getPower() << " ";
							}
						}
					}
				}
				
				list = stream.str();
				cout << list;
			} else {
				stream << "The circularlized Polynomial List is: \n"; 
				stream << "---> ";
				do {
					if(ptr->getNextNode() != this->getHead()) {
						stream << "("<<ptr->getCoeff() << ", " << ptr->getPower() << ")" << " --> ";
					} else {
						stream << "("<<ptr->getCoeff() << ", " << ptr->getPower() << ")";
					}
					ptr = ptr->getNextNode();
				} while(ptr != this->getHead());
				list = stream.str();
			
				cout << list << " ----> to start" << endl;
				cout << endl;
			}
		}
		
		//Printing the formatted list circular (old)
		/*void printListCircular() {
			node* ptr;
			string list;
			stringstream stream;
			ptr = this->getHead();
	
			cout << "The Linked List is: " << endl;
			stream << "---> ";
			do {
				if(ptr->getNextNode() != this->getHead()) {
					stream << ptr->getData() << " --> ";
				} else {
					stream << ptr->getData();
				}
				ptr = ptr->getNextNode();
			} while(ptr != this->getHead());
			list = stream.str();
			
			cout << list << " ----"<< endl;
			cout << "|";
			for(int i = 0; i < list.length()+3; i++) {
				cout << " ";
			}
			cout << "|" << endl;
			for(int i = 0; i < list.length()+5; i++) {
				cout << "-";
			}
			
			cout << endl;

			return;
		} */
	
		//Deleting the Linked List Experimental
		/*void deleteLinkedList() {
			node *ptr1, *ptr2;
			ptr1 = this->getHead();
			ptr2 = this->getHead();
			ptr2 = ptr2->getNextNode();
		
			while(ptr2 != NULL) {
				delete ptr1;
				ptr1 = ptr2;
				ptr2 = ptr2->getNextNode();
			}
	
			return;
		}*/
		
		void circularizeList() {
			node *ptr = this->getHead();
			
			while(ptr->getNextNode() != NULL) {
				ptr = ptr->getNextNode();
			}
			
			ptr->setNextNode(this->getHead());
			this->isCircular = true;
			
			return;
		}
		
		void unCircularizeList() {
			node *ptr = this->getHead();
			
			while(ptr->getNextNode() != this->getHead()) {
				ptr = ptr->getNextNode();
			}
			
			ptr->setNextNode(NULL);
			this->isCircular = false;
			
			return;
		}	
	private:
		node *head;
		bool isCircular;
};

#endif
