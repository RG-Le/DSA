#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v, int m) {
	for (int i = 0; i < m; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> Insertion_sort(vector<int> v, int m) {
	int curr_ele;
	for (int i = 1; i < m; i++) {
		curr_ele = v[i];
		int j = i-1;
		
		while (j >= 0 && v[j] > curr_ele) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = curr_ele;
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
	v = Insertion_sort(v, m);
	print(v, m);
	
	
	return 0;
}
