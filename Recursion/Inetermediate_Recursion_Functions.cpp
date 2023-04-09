#include <bits/stdc++.h>
using namespace std;

// GEOMETRIC SUM [1/2^0 + 1/2^1 + 1/2^3 + ... + 1/2^K]
double GeoSum(int k) {
	// BASE CASE
	if (k == 0) return 1;
	
	// RECURSIVE CALL
	double smallOP = GeoSum(k - 1);
	
	// CALCULATION
	double temp = pow(0.5, k);
	return smallOP + temp;
}

bool sorted(int a[], int n) {
	// BASE CASE
	if (n == 0 || n == 1) return true;
	
	if (a[0] > a[1]) {
		return false;
	}
	
	// RECURSION CALL
	bool isSmallSorted = sorted(a+1, n - 1);
	
	// CALCULATION
	return isSmallSorted;
}

int sumOfArray(int a[], int n) {
	// BASE CASE
	if (n == 0) return 0;
	
	// RECURSION CALL
	int smallOP = sumOfArray(a, n-1);
	
	// CALCULATION
	return smallOP + a[n];
}

bool isPresent(int a[], int n, int k) {
	if (n == 0) return false;
	
	bool smallOP = isPresent(a, n - 1, k);
	
	if (a[n] == k) return true;
	
	return smallOP;
}

int firstIndexOfEle(int a[], int n, int k, int i) {
	if (i == n) return -1;
	
	if (a[i] == k) return i;
	
	return firstIndexOfEle(a, n, k, i+1);
}

int lastIndexOfEle(int a[], int n, int k) {
	if (n == 0) return -1;
	
	if (a[n-1] == k) return n-1;
	
	return lastIndexOfEle(a, n - 1, k);
}

void printPosi(int a[], int n, int k, int i) {
	if (i == n) {
//		cout << "REACHED THE END!!" << endl;
		return;
	}
	
	if (a[i] == k) {
		cout << i << " ";
	}
	
	printPosi(a, n, k, i+1);
}

int countOccurences(int a[], int n, int k) {
	if (n == 0) return 0;
	
	int count = countOccurences(a, n-1, k);
	
	if (a[n-1] == k) {
		return count + 1;
	}
	return count;
}

bool checkPal(int a[], int s, int n) {
	if (s > n) return true;
	
	if (a[s] == a[n-1]) {
		checkPal(a,s+1,n-1);
	} else {
		return false;
	}
}

int main() {
//	int n;
//	cin >> n;
//	cout << GeoSum(n) << endl;
	
	int a[] = {1,2,2,2,2,1};

//	if (sorted(a, 6)) {
//		cout << "Sorted!!" << endl;
//	} else {
//		cout << "Not Sorted!!!" << endl;
//	}	

//	cout << sumOfArray(a, 6) << endl;
	
//	if (isPresent(a,6,6)) {
//		cout << "Present!!" << endl;
//	} else {
//		cout << "Not Present!!" << endl;
//	}
	
//	cout << firstIndexOfEle(a, 6, 2, 0) << endl;
//	cout << lastIndexOfEle(a, 6, 2) << endl;

//	printPosi(a, 6, 2, 0);
	
//	cout << countOccurences(a, 6, 2) << endl; 

//	if (checkPal(a,0,6)) {
//		cout << "PALINDROME!!" << endl;
//	} else {
//		cout << "NOT PALINDROME!!" << endl;
//	}
	
	return 0;
}
