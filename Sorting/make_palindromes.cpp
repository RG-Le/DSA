#include <bits/stdc++.h>
using namespace std;

bool checkPal(String s) {
	int los = s.length();
	mid = los/2;
	int j = los - 1;
	for (int i = 0; i < mid; i++) {
		if (s[i] != s[j]) {
			return false;
		} else {
			j--;
		}
	}
	return true;
	
}

int CNP(String s) {
	int count = 0;
//	Check first whether given string is palindrome:
	bool CP = checkPal(String s);
	if (!CP) {
		return count;
	}
	
	
	
}

int main() {
	String s;
	cout << "Enter a palindromic string: ";
	cin >> s;
	
	int count = CNP(String s);
	cout << "Number of possible palindromes are: " << count << endl;
	
}
