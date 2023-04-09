#include <bits/stdc++.h>
using namespace std;

int processArray(vector<int> &v) {
	bool two_digit_exists = false;
	int length = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > 9 && v[i] < 100) {
			two_digit_exists = true;
		}
		
		if (two_digit_exists && i+1 != v.size()) {
			if (v[i+1] > 9 && v[i+1] < 100) {
				if (v[i] < v[i + 1]) {
					v[i + 1] = 0;
				} else {
					v[i] = 0;
				}
			}
		}
		two_digit_exists = false;
	}
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) {
			v.erase(v.begin() + i);
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		length++;
	}
	return length;
}

int main() {
	vector<int> v;
	bool a = true;
	while(a) {
		int ip;
		cin >> ip;
		if (ip != -1) {
			v.push_back(ip);
		} else {
			a = false;
		}
	}
	int newLength;
	newLength = processArray(v);
	for (int i = 0; i < newLength; i++) {
		cout << v[i] << endl;
	}
	return 0;
}
