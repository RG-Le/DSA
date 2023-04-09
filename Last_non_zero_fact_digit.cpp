#include <bits/stdc++.h> 
using namespace std;

int get_fact(int n) {
	int p = 1;
	
	while (n > 0) {
		p = p*n;
		n = n-1;
	}
	
	return p;
}

void last_non_zero_fact(int n) {
	while (n != 0) {
		if (n % 10 != 0) {
			cout << abs(n % 10)<< endl;
			break;
		}
		n = n/10;
	}
}

int main() {
	int n;
	cin >> n;
	int fact = get_fact(n);
	last_non_zero_fact(fact);
	return 0;
}
