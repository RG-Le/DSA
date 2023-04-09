#include <bits/stdc++.h>
using namespace std;

void print(string a, int s, int e) {
	for (int i = s; i < e; i++) {
		cout << a[i];
	}
	cout << endl;
}

void printSubs(string a, int b[], int k) {
	int curr_sum = b[0];
	for (int i = 0; i < a.length(); i++) {
		for (int j = i+1; j < a.length(); j++) {
			if (curr_sum < k) {
				print(a,i,j);
			}
			curr_sum += b[j]; 
		}
		curr_sum = b[i];
	}
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9};
	string b = "abcdefg";
	int k = 5;
	printSubs(b, a, k);
	return 0;
}
