#include <bits/stdc++.h>
using namespace std;

int countFreq(string a) {
	int n = a.length() - 1;
	sort(a.begin(), a.end());
	cout << a << endl; 
	
	int max_c = 1;
	int mfc = a[0];
	int count = 1;
	
	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i+1]) {
			count++;
		} else {
			count = 1;
		}
		
		if (count > max_c) {
			max_c = count;
			mfc = a[i];
		}
	}
	
	cout << mfc << endl;
	return max_c;
}

int main() {
	string a = "sujfuessaaaaao";
	cout << countFreq(a) << endl;
	
	return 0;
}
