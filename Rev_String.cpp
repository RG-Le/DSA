#include <bits/stdc++.h> 
using namespace std;

void rev_print(string s, int n) {
	if (n < 0) {
		return;
	}
	
	cout << s[n];
	rev_print(s, n-1);
}

int main() {
	string s = "abcde";
	int len = s.length();
	rev_print(s, len-1);
	return 0;
}
