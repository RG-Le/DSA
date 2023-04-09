#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[5][5] = { {0,0,1,0,0}, 
					{0,0,0,1,0}, 
					{0,0,0,0,0}, 
					{0,1,0,0,0}, 
					{1,0,0,0,0} };
	int n = 5;
	for (int i = 0; i < n; i++) {
		int zc = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) {
				break;
			} else {
				zc++;
			}
		}
		if (zc == n) {
			cout << i << endl;
		}
	}
	
	return 0;
}
