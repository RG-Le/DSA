#include <bits/stdc++.h>
using namespace std;

int main() {
	int m;
	int n;
	cout << "Enter number of rows: ";
	cin >> m;
	cout << "\nEnter number of columns: ";
	cin >> n;
	
	int a[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Enter the element at position " << i << j << ":"; 
			cin >> a[i][j];
		}
	}
	
	// TO PASS 2D ARRAYS IN A FN USE VECTORS..........
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	
}
