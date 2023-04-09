#include <bits/stdc++.h>
using namespace std;

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// BRUTE FORCE
int happyEl(int a[], int n, int k) {
	int count = 0;	
	for (int i = 0; i < n; i++) {
		int curr_count = 0;
		swap(a[i], a[0]);
		print(a, n);
		int lm = a[0] - k;
		int ul = a[0] + k;
		for (int j = 1; j < n; j++) {
			if (curr_count >= 1) {
				break;
			}
			
			if (a[j] >= lm && a[j] <= ul) {
				curr_count++;
			}
		}
		count += curr_count;
		swap(a[i], a[0]);
	}
	return count;
}

int main() {
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	int a[n];
	
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl;
	print(a, n);
	
	int k;
	cout << "Enter value of k: ";
	cin >> k;
	cout << endl;
	
	cout << "The number of happy elements are: " << happyEl(a, n, k) << endl;
	
	return 0;
}
