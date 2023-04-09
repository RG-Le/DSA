#include <bits/stdc++.h>
using namespace std;

float getScore(int a[], int n) {
	float score = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] <= 0) {
			score = score - 1.0;
			return score; 
		} else if (a[i] % 2 != 0) {
			score = score + 1.0;
		} else {
			score = score - 0.5;
		}
	}
	return score;
} 

int main() {
	
	int a[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	
	cout << "SCORE: " << getScore(a, 3) << endl;
		
	return 0;
}
