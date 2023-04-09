// PROGRAM TO CONVERT DEC TO BIN
#include <bits/stdc++.h>
using namespace std;

vector<int> dtb(int n) {
	vector<int> a;
	while (n != 0) {
		a.push_back(n % 2);
		n = n/2;
	}

	return a;
}

bool checkPal(int n) {
	vector<int> a;
	while (n != 0) {
		a.push_back(n % 2);
		n = n/2;
	}
	
	int i= 0;
	int j = a.size() - 1; 
	while (i <= j) {
		if (a[i] != a[j]) {
			return false;
		}
		i++; j--;
	}
	return true;
}

bool setBitK(int n, int k) {
	vector<int> a = dtb(n);
	
	if (a[k] == 1) {
		return true;
	} else {
		return false;
	}
}
int main() {
	int n;
	cin >> n;
	vector<int> a = dtb(n);
	
		
	for (int i = a.size() - 1; i >= 0; i--) {
		cout << a[i];
	}
		
	cout << endl;
	bool b = checkPal(n);
	if (b) {
		cout << "PALINDROME!!!" << endl;
	} else {
		cout << "NOT PALINDROME!!!" << endl;
	}
	
	int k;
	cin >> k;
	bool c = setBitK(n,k);
	if (c) {
		cout << "SET BIT!!!" << endl;
	} else {
		cout << "UNSET BIT!!!" << endl;
	}
	return 0;
}
