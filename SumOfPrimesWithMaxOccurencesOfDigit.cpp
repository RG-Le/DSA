#include <bits/stdc++.h>
using namespace std;

bool isPrime(int i, int d, int maxDigitsInPrime) {
	bool c1 = false;
	bool c2 = false;
	if (i <= 1) {
		return false;
	}
	
	int max_div = floor(sqrt(i));
	
	for (int j = 2; j < 1 + max_div; j++) {
		if (i % j == 0) {
			return false;
		}
	}
	c1 = true;
	
	int count = 0;
	while (i != 0) {
		if (i % 10 == d) {
			count++;
		}
		i /= 10;
	}
	
	if (count == maxDigitsInPrime) {
		c2 = true;
	}
	
	
	if (c1 && c2) {
		return true;
	}
	return false;
		
}

vector<int> getPrimes(int N, int d, int maxDigitsInPrime) {
	vector<int> ans;
	int s = pow(10, N-1);
	int e = pow(10, N);
	
	for (int i = s; i < e; i++) {
		if (isPrime(i, d, maxDigitsInPrime)) {
			ans.push_back(i);
		}
	}
	
	return ans;
}

int getAns(int N, int d) {
	int sum = 0;
	int maxDigitsInPrime;
	
	if (N > 2) {
		maxDigitsInPrime = N - 2;
	} else {
		if (N == 1 || N == 2) {
			maxDigitsInPrime = 1;
		}
	}
	
	vector<int> primes = getPrimes(N, d, maxDigitsInPrime);
	
	for (int i = 0; i < primes.size(); i++) {
		cout << primes[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < primes.size(); i++) {
		sum += primes[i];	
	}
	
	return sum;	
}

int main() {
	
	int numberOfDigits;
	int digit;
	
	cin >> numberOfDigits >> digit;
	
	cout << getAns(numberOfDigits, digit) << " ";
	
	return 0;
}
