#include <bits/stdc++.h> 
using namespace std;

void print(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}

vector<int> bitFlip(vector<int> &a, int k) {
	int fi = a.size() - k;
	
	if (a[fi] == 0) {
		a[fi] = 1;
	} else {
		a[fi] = 0;
	}
	return a;
}

vector<int> numtobin(int n) {
	vector<int> a;
	while(n != 0) {
		a.push_back(n % 2);
		n = n/2;
	}
	return a;
}

void countCones(vector<int> &a) {
	int count = 1;
	int max = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 1 && a[i+1] == 1) {
			count++;
			if (count > max){
				max = count;
			}
		} else {
			count = 1;
		}
	}
	cout << max << endl;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> a = numtobin(n);
	print(a);
	cout << "Enter the bit to be flipped: ";
	int k;
	cin >> k;
	vector<int> b = bitFlip(a, k);
	print(b);
	cout << endl;
	countCones(b);
	
	return 0;
}
