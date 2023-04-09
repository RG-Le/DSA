#include <bits/stdc++.h>
using namespace std;

// MAJORITY ELEMENT ---> ELEMENT THAT OCCURS MORE THAN N/2 TIMES
// N == SIZE OF THE ARRAY
 
// BRUTE FORCE
void majority1(int a[], int n) {
	int b[n];
	for (int i = 0; i < n; i++) {
		b[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		b[a[i]]++;
	}
	
	int maj = n/2;
	
	for (int i = 0; i < n; i++) {
		if (b[i] > maj) {
			cout << i << " ";
		}
	}
	cout << endl;
}

// MOORES VOTING ALGORITHM
int majority(int a[], int n) {
	int curr_maj = a[0];
	int count = 1;

	for (int i = 1; i < n; i++) {
		if (a[i] == curr_maj) {
			count++;
		} else {
			count--;
			if (count == 0) {
				curr_maj = a[i];
				count = 1; 
			}
		}		
	}
	// assuming that majority element may not always exist
	int count2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == curr_maj) {
			count2++;
		}
	}
	
	if (count2 > n/2) return curr_maj;
	else return -1;
}

int main() {
	int a[] = {4,7,4,4,7,4,4,9,4,3};
	int n = 10;
	majority1(a, n);
	cout << majority(a, n) << endl;
	return 0;
}
