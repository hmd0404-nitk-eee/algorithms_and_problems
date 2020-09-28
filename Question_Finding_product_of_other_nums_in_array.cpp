/*
This program finds the porduct of all the numbers except the current number in an array.

This product is computed without using division operator.

Author: Harshal Dhake
*/

#include <iostream>
using namespace std;

int main() {
	int *array;
	int len;
	
	cout << "Enter the length of the input array: ";
	cin >> len;
	
	if(len > 0) {
		array = new int[len];
	} else {
		cout << "Invalid input!" << endl;
		return 0;
	}
	
	for(int i = 0; i < len; i++) {
		cout << "Enter the element " << i+1 << ": ";
		cin >> array[i];
	}
	
	cout << "The product array is:\n[ ";
	int prod = 1;
	for(int i = 0; i < len; i++) {
		prod = 1;
		for(int j = 0; j < i; j++) {
			prod *= array[j];
		}
		for(int j = i+1; j < len; j++) {
			prod *= array[j];
		}
		
		cout << prod << " ";
	}
	cout << "]" << endl;
	return 0;
}
