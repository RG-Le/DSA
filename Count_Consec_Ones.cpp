#include <bits/stdc++.h> 
using namespace std;

void print(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}

vector<int> numtobin(int n) {
	vector<int> a;
	while(n != 0) {
		a.push_back(n % 2);
		n = n/2;
	}
	return a;
}

void countCones(vector<int> &a) {
	int count = 1;
	int max = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 1 && a[i+1] == 1) {
			count++;
			if (count > max){
				max = count;
			}
		} else {
			count = 1;
		}
	}
	cout << max << endl;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> a = numtobin(n);
	print(a);
	cout << endl;
	countCones(a);
	
	return 0;
}
