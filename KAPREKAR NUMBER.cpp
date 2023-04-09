#include<bits/stdc++.h>
using namespace std;

bool iskaprekar(int n)
{
    if (n == 1)
    return true;

    int sq = n * n;
    int count = 0;
    while (sq)
    {
        count++;
        sq /= 10;
    }
 
    sq = n*n; 
    
    for (int i = 1; i < count; i++)
    {
        int eq = pow(10, i);

        if (eq == n)
            continue;
 
        int sum = sq/eq + sq % eq;
        if (sum == n)
        return true;
    }
    return false;
}
 

int main()
{
	int n;
	cin >> n;
	
	if (iskaprekar(n)) {
		cout << n << " is a kaprekar number" << endl;
	} else {
		cout << n << " is not a kaprekar number" << endl;
	}
	return 0;
}
