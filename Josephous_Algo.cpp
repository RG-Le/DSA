#include <bits/stdc++.h>
using namespace std;

int josep(int n, int k) {
	if (n == 1) { // Base Case
		return 1;
	} else {// Recursive Call
		return (josep(n-1, k) + k-1) % n + 1;
	}
}

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	
	cout << "Chosen Posi: " << josep(n, k) << endl;
	
	return 0;
}
