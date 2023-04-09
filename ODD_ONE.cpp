#include <iostream>
using namespace std;

int oddOne(int a[], int n) {
	int count = 1;
	for (int i = 0; i < n-1; i++) {
		if (a[i + 1] == a[i]) {
			count++;
		} else {
			if (count % 2 != 0) {
				return a[i];
			} else {
				count = 1;
			}
		}
	}
	
//	EDGE CASE
	if (count == 1) {
		return a[n-1];
	}
}

int main() {
	int a[] = {1,1,2,2,3};
	cout << oddOne(a,5);
	return 0;
}
