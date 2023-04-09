#include <bits/stdc++.h>
using namespace std;

long long maxSum(int arr[], int n){
        // Your code here
        int max_curr = INT_MIN;
        int max_end = 0;
        
        for (int i = 0; i < n; i++) {
            max_end += arr[i];
            
            if (max_curr < max_end) {
                max_curr =  max_end;
            }
            
            if (max_end < 0) {
                max_end = 0;
            }
        }
      return max_curr;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	
	cout << "Max sum of subarray is: " << maxSum(a, n);
	
	return 0;
}
