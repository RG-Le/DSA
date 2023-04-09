#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/// SELECTION SORT
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


//// LINEAR SEARCH
void linearSearch(int a[], int n, int k) {
	for (int i = 0; i < n; i++) {
		if (a[i] == k) {
			cout << "Element found at index " << i << ": " << a[i] << endl;
			break;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int a[n + 2];
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	int k;
	cin >> k;
	linearSearch(a, n, k);	
	selectionSort(a, n);
	return 0;
}
