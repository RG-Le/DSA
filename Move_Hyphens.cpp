#include <bits/stdc++.h>
using namespace std;

void moveH(char a[]){
    int n = strlen(a)-1;
    for (int i = n; i >= 0; i--)
        if (a[i] != '-')
            swap(a[n--], a[i]);
}

int main() {
	char a[] = "abcd-eff-g";
    moveH(a);
    cout << a;
	return 0;
}
