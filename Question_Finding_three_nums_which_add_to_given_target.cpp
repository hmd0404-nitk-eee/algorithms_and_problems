/* This program find the set of 3 numbers which add to a given target number from an array (More efficient algo) */

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

int main() {
	int array[MAXSIZE], n, target;
	
	cout << "Enter the number of elements: ";
	cin >> n;
	
	cout << "Enter the array: ";
	for(int i = 0; i < n; i++) {
		cin >> array[i];
	}
	
	cout << "Enter the target: ";
	cin >> target;
	
	sort(array, array + n -1);
	
	int row = 0, col = 0;
	bool found = false;
	for(int i = 0; i < n; i++) {
		int sum = target - array[i];
		row = 0; 
		col = n-1;
		found = false;
		
		while(row < n && col >= 0 && !found) {
			if(sum > array[row] +array[col]) {
				col--;
			} else if(sum < array[row] + array[col]) {
				row++;
			} else if(sum == array[row] + array[col]) {
				found = true;
			}
		}
		if(found) {
			cout << "Triplet " << i+1 << ": " << array[i] << " " << array[row] << " " << array[col] << endl; 
		}
	}
	
	return 0;
}
