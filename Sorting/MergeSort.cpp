#include <iostream>
using namespace std;

void mergeSort(int a[], int s, int e) {
	if (s >= e) {
		return;
	}
	
	int mid = (s+e)/2;
	int x[50]; int y[50];
	
	for(int i = 0; i <= mid; i++) {
		x[i] = a[i];
	}
	
	for(int i = mid + 1; i <= e; i++) {
		y[i] = a[i];
	}
	
	mergeSort(a, s, mid);
	mergeSort(a,mid+1, e);
}

void mergeSort1(int x[], int y[], int a[], int s, int e) {
	int i = s;
	int k = s;
	int mid = (s+e)/2;
	int j = mid + 1;
	
	while (i <= mid && j <= e) {
		if (x[i] < y[j]) {
			a[k] = x[i];
			i++; k++;
		} else {
			a[k] = y[j];
			j++; k++;
		}
	}
	
	while (i <= mid) {
		a[k] = x[i];
		k++; i++;
	}
	
	while (j <= e) {
		a[k] = y[j];
		k++; j++;
	}
}

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int a[] = {1,5,0,2,8,7,40,20,56,11};
	int n = 10;
	
	printArr(a, n);
	cout << endl;
	mergeSort(a, 0, 9);
	printArr(a, n);
	
	 
}
