#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int rem_dups1(vector<int> &a) {
	int n = a.size();
	unordered_map<int, bool> mymap;
	
	for (int i = 0; i < n; i++) {
		if (mymap.count(a[i]) == 0) {
			mymap[a[i]] = true;
		} else {
			return a[i];
		}
	}
}

vector<int> rem_dups(vector<int> &a) {
	int n = a.size();
	vector<int> op;
	unordered_map<int, bool> mymap;
	
	for (int i = 0; i < n; i++) {
		if (mymap.count(a[i]) == 0) {
			mymap[a[i]] = true;
			op.push_back(a[i]);
		}
	}
	return op;
}

int main() {
	vector<int> v{1,2,3,4,5,3};
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
//	vector<int> op;
	int op = rem_dups1(v);
//	for (int x : op) {
//		cout << x << " ";
//	}
	cout << op << endl;
	return 0;
}
