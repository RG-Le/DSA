#include <bits/stdc++.h>
using namespace std;

// PRINT FUNCTION USING RECURSION
void printR(int n) {
	// BASE CASE
	if (n == 0) return;
	
	// RECURSION CALL
	printR(n-1);
	
	// CALCULATION
	cout << n << " ";
}

// COUNT NUMBER OF DIGITS
int count(int n) {
	// BASE CASE
	if (n == 0) return 0;
	
	// RECURSION CALL
	int smallOP = count(n/10);
	
	// CALCULATION
	return smallOP + 1;
}

int mul(int a, int b) {
	// BASE CASE
	if (b == 0 || a == 0) return 0;
	
	// RECURSION CALL
	int smallOP = mul(a, b - 1);
	
	// CALCULATION
	return smallOP + a;
}

int countZeros(int n) {	
	// BASE CASE
	if (n == 0) return 0;
	
	// RECURSION CALL
	int smallOP = countZeros(n/10);
	
	// CALCULATION	
	int ld = n % 10;
	if (ld == 0) {
		return smallOP + 1;
	} else {
		return smallOP;
	}
}

int main() {
	int n;
	cin >> n;
	
//	printR(n);
//	cout << count(n) << endl;
//	cout << mul(5,n) << endl;
	cout << countZeros(n) << endl;	
	
	return 0;
}
