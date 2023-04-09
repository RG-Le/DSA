#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > getIP(int m, int n) {
	vector<vector<int> > v;
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			cout << "Enter the elemen at position " << i << j << ": ";
			int a;
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);	
	}
	return v;
}

void row_print(vector<vector<int> > v, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void spiral_print(vector<vector<int> > v, int m, int n) {
	int sr = 0; int er = m - 1;
	int sc = 0; int ec = n - 1;
	int count = 0;
	vector<int> ans;
	while (sr <= er && sc <= ec) {
		// Printing sr	
		for(int i = sc; i <= ec; i++) {
			ans.push_back(v[sr][i]);
			count++;
		}
		sr++;
		if (count == m*n) break;
		
		// Printing ec
		for(int i = sr; i <= er; i++) {
			ans.push_back(v[i][ec]);
			count++;
		}
		ec--;
		if (count == m*n) break;
		
		// Printing er
		for(int i = ec; i >= sc; i--) {
			ans.push_back(v[er][i]);
			count++;
		}
		er--;
		if (count == m*n) break;
		
		// Printing sc
		for(int i = er; i >= sr; i--) {
			ans.push_back(v[i][sc]);
			count++;
		}
		sc++;
		if (count == m*n) break;
	}
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	 
}

int main() {
	
	vector<vector<int> > v;
	int m;
	int n;
	
	cout << "Enter no of rows: ";
	cin >> m;
	cout << "Enter no of columns: ";
	cin >> n;
	
	v = getIP(m, n);
	row_print(v, m, n);
	spiral_print(v, m, n);
	
	return 0;
}
