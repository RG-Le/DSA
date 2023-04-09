#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}

int vecTnum(vector<int> &a) {
	int num = 0;
	for (int i = 0; i < a.size(); i++) {
		int temp = a[i]*pow(10,i);
		num = num + temp;
	}
	return num;
}

void getDiff(int n) {
	vector<int> a;
	int b = n;
	
	while (b != 0) {
		a.push_back(b % 10);
		b = b/10;
	}
//	print(a);
	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 6) {
			a[i] = 9;
		}
	}
//	print(a);
	int d = vecTnum(a);
	cout << d << endl;
	cout << "Max Difference: " << abs(n-d);

}

int main() {
	
	int n;
	cin >> n;
	
	getDiff(n);
		
	return 0;
}
