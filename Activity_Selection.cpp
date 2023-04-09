#include <bits/stdc++.h> 
using namespace std;

void printGames(int a[], int b[], int n) {
	int i, j = 0;
	cout << i << " ";
	while (i < n) {
		i++;
		if (a[i] > b[j]) {
			cout << i << " ";
		}
	    j++;
	}
	
}

int main() {
	int n = 5;
	int st[] = {1,10,5,24,6};
	int et[] = {9,20,10,15,5};
	
	printGames(st, et, n);
		
	return 0;
}
