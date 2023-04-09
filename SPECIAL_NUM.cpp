#include <iostream>
using namespace std;

int SPS(int a) {
	int sum, prod;
	sum = (a % 10) + (a/10);
	prod = (a%10) * (a/10);
	return sum + prod;
}

void getSpecialNums(int m, int n) {
	int t = n - m + 1;
	int a[t];
	for (int i = 0; i < t; i++) {
		a[i] = m;
		m++;
	}
	
	for (int i = 0; i < t; i++) {
		if (a[i] == SPS(a[i])) {
			cout << a[i] << " ";
		}
	}
	
	cout << endl;
	
	// EDGE CASES
	if (m/100 != 0 || n/100 != 0) {
		cout <<  "2 DIGIT NUMBER LIMITS ALLOWED" << endl;
	}
	
	if (m/10 == 0 || n/10 == 0) {
		cout <<  "2 DIGIT NUMBER LIMITS ALLOWED" << endl;
	}
}

int main() {
	int m;
	int n;
	cin >> m >> n;
	
	getSpecialNums(m,n);
		
	return 0;
}
