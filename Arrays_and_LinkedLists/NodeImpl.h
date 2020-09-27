/*
CS202 Assignment 1

Name: Harshal Dhake - 191EE212

This is the header file for Handling Linked Lists Nodes in C++.
*/
#include <iostream>


#ifndef NodeImpl
#define NodeImpl

class Node {
	private:
		float data;
		float xpos;
		float ypos;
		float coeff;
		int power;
		Node *ptrNextNode;
		
	public:
		//Constructors
		Node() {
			data = 0;
			xpos = 0;
			ypos = 0;
			ptrNextNode = NULL;
		}
		
		Node(float value) {
			data = value;
			ptrNextNode = NULL;
		}
		
		Node(float value, float i, float j) {
			data = value;
			xpos = i;
			ypos = j;
			ptrNextNode = NULL;
		}
	
		Node(float c, int e) {
			coeff = c;
			power = e;
			ptrNextNode = NULL;
		}
	
		//Basic Operations
		float getData() {
			return data;
		}
	
		int getXpos() {
			return xpos;
		}
		
		int getYpos() {
			return ypos;
		}
	
		int getPower() {
			return power;
		}
	
		float getCoeff() {
			return coeff;
		}
	
		void setData(float value) {
			data = value;
			return;
		}
		
		void setPower(int pow) {
			power = pow;
			return;
		}
	
		void setNextNode(class Node* nextNode) {
			ptrNextNode = nextNode;
			return;
		}
	
		class Node* getNextNode() {
			return ptrNextNode;
		}
		
		//Copies fromNode to current and overwrites data at current node
		void copyNodes(class Node* from) {
			this->setData(from->getData());
			this->setNextNode(from->getNextNode());
			
			return;
		}
};

typedef class Node node;

#endif
