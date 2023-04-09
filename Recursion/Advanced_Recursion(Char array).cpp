#include <bits/stdc++.h>
using namespace std;

void print(char a[]) {
	// BASE CASE
	if (a[0] == '\0') {
		return;
	}	 
	
	cout << a[0];
	print(a+1);
}

void rev_print(char a[]) {
	// BASE CASE
	if (a[0] == '\0') {
		return;
	}	 
	
	rev_print(a+1);	
	cout << a[0];
}

int len(char a[]) {
	// BASE CASE
	if (a[0] == '\0') {
		return 0;
	}
	
	// RECURSIVE CALL & CALCULATION
	return 1 + len(a+1);
}

void replace_char(char a[]) {
	if (a[0] == '\0') return;
	
	if (a[0] == 'a') {
		a[0] = 'x';
	}
	replace_char(a+1);
}

void remove_char(char a[]) {
	if (a[0] == '\0') {
		return;
	}
	
	if (a[0] != 'a') {
		remove_char(a + 1);
    } else {
    	for (int i = 0; a[i] != '\0'; i++) {
    		a[i] = a[i+1];
		}
		remove_char(a);
	}
}

void remove_consec_dup(char a[]) {
	if (a[0] == '\0') return;
	
	if (a[0] == a[1]) {
		for (int i = 0; a[i] != '\0'; i++) {
    		a[i] = a[i+1];
		}
		remove_consec_dup(a);	
	} else {
		remove_consec_dup(a + 1);
	}
}

void print_subsequences(string ip, string op) {
	if (ip.length() == 0) {
		cout << op << endl;
		return;
	}
	
	print_subsequences(ip.substr(1), op); // exclude
	print_subsequences(ip.substr(1), op + ip[0]); // include

}

void print_subsequences2(char ip[], char op[], int i) {
	if (ip[0] == '\0') {
		op[i] = '\0';
		cout << op << endl;
		return;
	}
	op[i] = ip[0];
	print_subsequences2(ip + 1, op, i+1); // include
	print_subsequences2(ip + 1, op, i); // exclude
}

void store_subsequences(string ip, string op, vector<string> &v) {
	if (ip.length() == 0) {
		v.push_back(op);
		return;
	}
	
	store_subsequences(ip.substr(1), op, v); // exclude
	store_subsequences(ip.substr(1), op + ip[0], v); // include

}

int convert_to_int(char a[], int n) {
	if (n == 0) return 0;
	
	int smallAns = convert_to_int(a, n-1);
	int last_digit = a[n-1] - '0';
	int ans = smallAns * 10 + last_digit;
	
	return ans;
	
}

void print_permutations(char str[], int i) {
	if (str[i] == '\0') {
		cout << str << endl;
		return;
	}
	
	for (int j = i; str[j] != '\0'; j++) {
		swap(str[i], str[j]);
		print_permutations(str, i+1);
		swap(str[i], str[j]);
	}
}

int count_ways(int n) {
	if (n == 0 || n == 1) return 1;
	if (n < 0) return 0;
	return count_ways(n-1) + count_ways(n-2) + count_ways(n-3);
}

int toh(int n) {
	if (n == 0) return 0;	
	return toh(n-1) + 1 + toh(n-1);
}

void print_steps(int n, char s, char d, char h) {
	if (n == 0) return;
	
	print_steps(n-1, s, h, d);
	cout << "Moving Disk " << n << " from " << s << " to " << d << endl;
	print_steps(n-1, h, d, s);
}

int main() {
	
// PRINT AND REVERSE PRINT

//	char a[] = "abcewfejnaaaknkakakaa";
//	print(a);
//	cout << endl;
//	
//	rev_print(a);


//  LENGTH OF CHAR	
//	cout << "\nLength: " << len(a);

//	REPLCAE THE CHAR 'A' WITH 'X'
//	replace_char(a);
//	cout << endl;
//	print(a);

//	REMOVE THR CHAR 'A'
//	remove_char(a);
//	cout << endl;
//	print(a);

//	REMOVE CONSECUTIVE DUPLICATES
//	remove_consec_dup(a);
//	print(a);

//	PRINT ALL SUBSEQUENCES OF A STRING
//	cout << endl;
//	string ip;
//	cin >> ip;
//	string op = "";
//	print_subsequences(ip, op);

//  PRINT ALL SUBSEQUENCES OF A CHAR ARRAY
//	char ip[100];
//	cin >> ip;
//	char op[10];
//	print_subsequences2(ip, op, 0);

// 	STORE ALL SUBSEQUENCES OF A STRING
//	string in;
//	cin >> in;
//	string out = "";
//	vector<string> v;
//	store_subsequences(in, out, v);
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << endl;
//	}
	
//	CONVERT A CHAR TO INT	
//	char str[] = "12345";
//	int n = len(str);
//	int a = convert_to_int(str, n);
//	cout << a << endl;
	
//  PRINT ALL PERMUTAIONS OF THE STRING
	char a[] = "abcd";
	print_permutations(a, 0);
	
//	STAIRCASE PROBLEM
//	int n;
//	cin >> n;
//	cout << count_ways(n) << endl;

//  TOWER OF HANOI
//	int n;
//	cin >> n;
//	cout << toh(n) << endl;
//	// A: SOURCE	C: DESTINATION	B: HELPER
//	print_steps(n, 'A', 'C', 'B');
		
	return 0;
}
