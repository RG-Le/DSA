#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int> > v) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void transpose(vector<vector<int> > &v, int i, int n) {
	if (i == n-1) return;
	
	for (int j = i; j < n; j++) {
		swap(v[i][j], v[j][i]);
	}
	
	transpose(v, i + 1, n);
}


void reverse(vector<vector<int> > &v, int i, int n) {
	if (i == n) return;
	int e = n -1; 
	for (int j = 0; j < e; j++) {
		swap(v[i][j], v[i][e--]);
	}
	
	reverse(v, i+1, n);
}

// discuss in detail about the osi reference model

int main() {
	vector<vector<int> > v = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	print(v);
	int n = v.size();
	transpose(v, 0, n);
	print(v);	
	reverse(v, 0, n);
	print(v);
	return 0;
}
