#include <bits/stdc++.h>
using namespace std;

int hourGlass(vector<vector<int> > arr) {
	int max = INT8_MIN;
    int num_of_hg = 16;
    int sum = 0;
    int sr = 0;
    int er = 2;
    int sc = 0;
    int ec = 2;
    int count = 0;
    
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
        
            // top and bottom row hourglass sum
            for (int i = sc; i <= ec; i++) {
                sum += arr[sr][i] + arr[er][i];
            }
            // middle element of hourglass
            sum += arr[(sr+er)/2][(sc+ec)/2];
            if (sum > max) {
                max = sum;
            }
            sum = 0;
            cout << "Start Column: " << sc << " End Column: " << ec << endl;
            sc++; ec++;
        }
        cout << "Start Row: " << sr << " End Row: " << er << endl;
        sr++; er++; 
        sc = 0; 
        ec = 2;
        sum = 0;  
    }
    
    return max;
}

int main() {
	
	vector<vector<int> > input;
	
	for (int i = 0; i < 6; i++) {
		vector<int> temp1;
		for (int j = 0; j < 6; j++) {
			int k;
			cin >> k;
			temp1.push_back(k);
		}
		input.push_back(temp1);
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Max Hour Glass Sum is " << hourGlass(input) << endl;
	
	return 0;
}
