/*
This program uses Selection Sort to sort the input array
*/

#include <iostream>
using namespace std;

int main () {
	int *array, size;
	
	cout << "Enter the size of the array: ";
	cin >> size;
	array = new int[size];
	
	cout << "Enter the array elements: ";
	for(int i = 0; i < size; i++) {
		cin >> array[i];
	}
	
	cout << "The sort array using Selection Sort is: ";
	int smallest, smallestIndex;
	for(int i = 0; i < size; i++) {
		smallest = array[i];
		smallestIndex = i;
		for(int j = i+1; j < size; j++) {
			if(array[j] < smallest) {
				smallest = array[j];
				smallestIndex = j;
			}
		}
		
		array[smallestIndex] = array[i];
		array[i] = smallest; 
	}
	
	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	} 
	cout << endl;
	
	return 0;
}
