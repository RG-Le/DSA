#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v, int m) {
	for (int i = 0; i < m; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> Bubble_sort(vector<int> v, int m) {
	for (int i = 0; i < m; i++) {
		bool flag = false; 
		for (int j = 0; j < m - 1; j++) {
			if (v[j] > v[j+1]) {
				flag = true;
				swap(v[j], v[j+1]);
			}
		}
		// NO SWAPPING HAPPENED
		if (!flag) break;
	}
	return v;
}

vector<int> Opt_Bubble_sort(vector<int> v, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (v[j] > v[j+1]) {
				swap(v[j], v[j+1]);
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
	v = Bubble_sort(v, m);
	print(v, m);
	
	
	return 0;
}
