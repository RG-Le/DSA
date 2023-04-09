#include <bits/stdc++.h>
using namespace std;

// SEARCH IN A ROTATED SORTED ARRAY
int searchRotated(int a[], int n, int key) {
	int s = 0;
	int e = n;
	
	while (s <= e) {
		int mid = (s+e)/2;
		if (a[mid] == key) {
			return mid;
		}
		
		if (a[s] <= a[mid]) {
			if (key >= a[s] && key <= a[mid]) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		} else {
			if (key >= a[mid] && key <= a[e]) {
				s = mid + 1;
			} else {
				e = mid - 1;
			}
		}	
	}
	return -1;
}

int main() {
	int a[] = {3,4,5,6,1,2};
	int n = 6;
	int key = 1;
	cout << searchRotated(a,n,key);
	
	return 0;
}
