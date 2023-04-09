#include <bits/stdc++.h> 
using namespace std;

void print(vector<vector<int> >& a, int n) {
	for (int i = 0;i < n; i++) {
		cout << "[ ";
		for (int j = 0; j < 2; j++) {
			cout << a[i][j] << " ";
		}
		cout << " ]," << " ";
	}
	cout << endl;
}

vector<vector<int> > short_a(vector<vector<int> > &a, int m, int n) {
	int lm = a[n][0];
	int up = a[m][1];
	a.erase(a.begin() + n);
	print(a, a.size());
	a[n][0] = lm;
	a[n][1] = up;
	return a;
}

vector<vector<int> > merge(vector<vector<int> >& a) {
	
	for (int i = 1; i < a.size(); i++) {
		int upp = a[i-1][1];
		int n_upp = a[i][1];
		if (upp >= n_upp) {
			a = short_a(a,i, i-1);
		}
	}
	
	return a;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int> > v;
	
	for (int i = 0; i < n; i++) {
		vector<int> a;
		for (int j = 0; j < 2; j++) {
			int val;
			cin >> val;
			a.push_back(val);
		}
		v.push_back(a);
	}
	
	print(v, n);
	cout << endl;
	v = merge(v);
	print(v, v.size());
	
	return 0;
}
