#include <bits/stdc++.h> 
using namespace std;

int pow(int a, int b) {
	// BASE CASE
	if (b == 0) return 1;
	
	// RECURSION CALL
	int smallOP = pow(a, b-1);
	
	// CALCULATION
	return a*smallOP;
	
}

int main () {
	int n;
	cin >> n;
	int m;
	cin >> m;
	int ans;
	ans = pow(n, m);
	cout << ans;
	return 0;
}
