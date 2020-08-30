/* This code uses O(n lgn) algorithm to find whether two numbers exist in an array which add up to a given  number */

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

bool binarySearch(int arr[], int init, int final, int key) {
	if(init > final) {
		return false;
	} else {
		int mid = init + final;
		mid /= 2;
		int mid_elem = arr[mid];
		
		if(key > mid_elem) {
			return binarySearch(arr, mid+1, final, key);
		} else if(key < mid_elem) {
			return binarySearch(arr, init, mid-1, key);
		} else {
			return true;
		}
	}
}

int main() {
	int array[MAXSIZE] = {0}, target;
	int n;
	bool found = false;
	
	cout << "Enter the array length: ";
	cin >> n;
	cout << "Enter the array: ";
	for(int i = 0; i < n; i++) {
		cin >> array[i];
	}
	
	cout << "Enter the target: ";
	cin >> target;
	
	sort(array, array+n-1);
	
	for(int i = 0; i < n; i++) {
		if(!found) {
			int key = target - array[i];
			found = binarySearch(array, 0, n-1, key);
		} else{
			break;
		}
	}
	
	cout << found << endl;
	
	return 0;
}
