/* This progrma uses Merge Sort to Sort the input array using Recursion */

#include <bits/stdc++.h>
using namespace std;

void merge(int* array, int start, int mid, int end) {
	int *temp = new int[end - start + 1];
	int i = start, j = mid + 1, tempcount = 0;
	
	while(i <= mid && j <= end) {
		if(array[i] > array[j]) {
			temp[tempcount] = array[j];
			j++;
		} else {
			temp[tempcount] = array[i];
			i++;
		}
		tempcount++;
	}
	
	while(i <= mid) {
		temp[tempcount] = array[i];
		tempcount++;
		i++;
	}
	
	while(j <= end) {
		temp[tempcount] = array[j];
		tempcount++;
		j++;
	}
	
	for(int k = start; k <= end; k++) {
		array[k] = temp[k - start];
	}
	
	return;
}

void mergeSort(int* array, int start, int end) {
	if(start < end) {
		int mid = start + end;
		mid >>= 1;
		mergeSort(array, 0, mid);
		mergeSort(array, mid+1, end);
		
		merge(array, 0, mid, end);
		
	}
	return;
}

int main() {
	int *array, n;
	
	cout << "Enter the size of the array: ";
	cin >> n;
	
	array = new int[n];
	
	cout << "Enter the array: ";
	for(int i = 0; i<n; i++) {
		cin >> array[i];
	}
	
	mergeSort(array, 0, n-1);
	
	cout << "The sorted array is: ";
	for(int i = 0; i < n; cout << array[i++] << " ");
	
	return 0;
}
