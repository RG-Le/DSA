#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	int smallOP1 = fib(n - 1);
	int smallOP2 = fib(n - 2);
	
	return smallOP1 + smallOP2;
}

void fib1(int n) {
	int t1 = 0;
	int t2 = 1;
	int count = 0;
	
	while (count <= n) {
		if (count == 0) {
			cout << 0 << " ";
		} else if (count == 1) {
			cout << 1 << " ";
		} else {
			int nt = t1 + t2;
			t1 = t2;
			t2 = nt;
			cout << nt << " ";
		}
		count++;
	}
	
}

int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	
//	for (int i = 0; i <= n; i++) {
//		cout << fib(i) << " ";
//	}
//	
	fib1(n);
	
	return 0;
}
