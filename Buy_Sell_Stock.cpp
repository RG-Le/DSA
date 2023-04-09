#include <bits/stdc++.h> 
using namespace std;

int getProfit(vector<int> v) {
	int maxPro = 0;
	int minPrice = INT_MAX;
	
	for (int i = 0; i < v.size(); i++) {
		minPrice = min(minPrice, v[i]);
		maxPro = max(maxPro, v[i] - minPrice);
	} 
	
	return maxPro;
}

int main() {
	vector<int> v = {7,1,2,5,6,4};
	cout << "Max Profit: " << getProfit(v) << endl;
	return 0;
}
