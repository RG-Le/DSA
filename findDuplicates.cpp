#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums) {
	int nl = nums.size();
        vector<int> v(nl, 0);
        
        for (int i = 0; i < nl; i++) {
            v[nums[i]]++;
            if (v[nums[i]] > 1) {
                return nums[i];
            }
        }
    return 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		a.push_back(val);
	}
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " "; 
	}
	cout << endl;
	
	cout << "Duplicate " << findDuplicate(a) << endl;
	
	
	return 0;
}
