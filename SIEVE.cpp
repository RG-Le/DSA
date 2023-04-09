#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void getPrimes(int n) {
	vector<int> a;
	
	for (int i = 0; i < n; i++) {
//		if (i == 0 || i == 1) {
//			cout << i << " ";
//		}
		
		if (i == 2) {
			cout << i << " ";
			a.push_back(i);
		}
		
		if (i > 2) {
			int count = 0;
			for (int j = 0; j < a.size(); j++) {
				if (i % a[j] == 0) {
					count++;
				} 
			} 
			if (count == 0){
				a.push_back(i);
				cout << i << " ";
			}
		}	
	}	
}

// SEIVE ALGORITHM
void getPrimes2(int n) {
	
	vector<bool> a(n+1, true);
	a[0] = a[1] = false;
	for (int i = 2; i <= n; i++) {
    	if (a[i] && (long long)i * i <= n) {
        	for (int j = i * i; j <= n; j += i)
            	a[j] = false;
    	}
	}
	
	
	if (n >= 1) {
		cout << 0 << " " << 1 << " ";
	} else {
		cout << 0 << " ";
	} 
	for (int i = 2; i < a.size(); i++) {
		if (a[i] == true) {
			cout << i << " ";
		}
	}
}


int main(){
	int n;
	cin >> n;
	
	getPrimes(n);
	
	return 0;
}
