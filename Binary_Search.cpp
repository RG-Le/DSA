#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min])
        min = j;
    }
    swap(&a[min], &a[i]);
  }
  
  for (int i = 0; i < n; i++) {
  	cout << a[i] << " ";
  }
}

void binarySearch(int a[], int s, int e, int k) {
	int mid = (s + e)/ 2;
	if (k > a[mid]) {
		binarySearch(a, mid + 1, e, k);
	} else if (k < a[mid]) {
		binarySearch(a, s, mid - 1, k);
	} else if (k == a[mid]) {
		cout << a[mid] << " : " << k << endl;
	} else {
		cout << "ELEMENT NOT FOUND!!" << endl;
	}
}

int main () {
	int n;
	cin >> n;
	int a[n + 2];
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	int k;
	cin >> k;
	selectionSort(a, n);
	cout << endl;
	binarySearch(a, 0, n, k);	
	return 0;
}
