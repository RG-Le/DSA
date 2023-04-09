#include <bits/stdc++.h>
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int partition(int a[], int s, int e) {
	int i = s;
	int pivot = a[e];
	
	for (int j = s; j <= e - 1; j++) {
		if (a[j] < pivot) {
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[e]);
	return i;
}

void quickSort(int a[], int s, int e) {
	if (s >= e) return;
	
	int p = partition(a, s, e);
	quickSort(a, s, p-1);
	quickSort(a, p+1, e);
}

int main() {
	int a[] = {8,5,2,1,7,3,4};
	print(a, 7);
	quickSort(a, 0, 6);
	print(a, 7);
	return 0;
}
