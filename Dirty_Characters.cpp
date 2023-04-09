#include <bits/stdc++.h>
using namespace std;

void rm_dc(string a, string b) {
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				a.erase(a.begin() + i);
	//			cout << a << endl;
			}
		}
	}
	
	cout << a << endl;
}

int main() {
	string a = "abcde";
	string b = "bcfgh";
	rm_dc(a, b);
	return 0;
}
