#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v, int m) {
	for (int i = 0; i < m; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> Selection_sort(vector<int> v, int m) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (v[i] > v[j]) {
				swap(v[i], v[j]);
			}
		}
	}
	return v;
}

int main() {
	int m;
	cout << "Enter the length of the array: ";
	cin >> m;
	
	vector<int> v;
	cout << "Enter the elements: ";
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	print(v, m);
	v = Selection_sort(v, m);
	print(v, m);
	
	
	return 0;
}
