#include <bits/stdc++.h>
using namespace std;

int processArray(int a[], int n) {
	int ans;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		if (a[i] == 100) {
			ans = a[i];
			return ans;
		}
		if (a[i] > 100) {
			temp = a[i];
			count++;
			if (count == 1) {
				ans = a[i];
			} else {
				if (temp < ans) {
					ans = temp;
				}
			}
		}
	}
	return ans;
}

int main() {
	int n = 4;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = processArray(a, n);
	cout << ans << " ";
	return 0;
}
