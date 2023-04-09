#include <bits/stdc++.h>
using namespace std;
/// BRUTE FORCE
vector<int> repeatedMissing(vector<int> &v) {
	vector<int> ans;
	int n = v.size();
	vector<int> helper(n + 1, 0);
	
	for (int i = 0; i <= n; i++) {
		if (helper[v[i]] == 1) {
			ans.push_back(v[i]);
		}
		helper[v[i]] += 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (helper[i] == 0) {
			ans.push_back(i);
			return ans;
		}
	}
	return ans;
}



int main() {
	vector<int> v = {3,1,2,5,3};
	vector<int> ans = repeatedMissing(v);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
