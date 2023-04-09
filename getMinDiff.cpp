#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int a[], int n, int k) {
        // code here
        if (n == 0) {
            return -1;
        }
        int avg = 0;
        for (int i  = 0; i < n; i++) {
            avg = avg + a[i];
        }
        
        avg = avg/n;
        
        for (int i = 0; i < n; i++) {
            if (a[i] < k) {
                a[i] = a[i] + k;
            } else {
                a[i] = a[i] - k;
            }
        }
        
        sort(a, a + n);
        return (a[n-1] - a[0]);
        
    }

int main() {
	int a[] = {1,5,8,10};
	int n = 4;
	int k = 2;
	
	cout << getMinDiff(a,n,k);
	
	return 0;
}
