/*This code find the number of inversion in an array using a O(n lgn) algorithm*/
#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

int merge_with_inversions_count(int arr[], int init, int mid, int final) {
	int i = init, j = mid+1, k = init;
	int temp[MAXSIZE];
	int inv_count = 0;

	while(i <= mid && j <= final) {
		if(arr[i] > arr[j]) {
			inv_count += mid - i + 1;
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	
	while(i <= mid) {
		temp[k++] = arr[i++];
	}
	
	while(j <= final) {
		temp[k++] = arr[j++];
	}
	
	for(int c = init; c <= final; c++){
		arr[c] = temp[c];
	}
	
	return inv_count;
}

int divideInHalf(int arr[], int init, int final) {
	int mid = 0, inv_count = 0;
	if(init < final) {
		mid = init + final;
		mid /= 2;
		
		inv_count += divideInHalf(arr, init, mid);
		inv_count += divideInHalf(arr, mid+1, final);
		
		inv_count += merge_with_inversions_count(arr, init, mid, final);
	}
	
	return inv_count;
}

int main() {
	int array[MAXSIZE] = {0}, n;
	
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the array: ";
	for(int i = 0; i < n; i++) {
		cin >> array[i];
	}
	
	
	cout << "There are " << divideInHalf(array, 0, n-1) << " inversions in the given array" <<endl;
	return 0;
}
