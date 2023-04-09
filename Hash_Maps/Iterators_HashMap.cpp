#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<string, int> mymap;
	mymap["abc"]  = 1;
	mymap["abc1"]  = 2;
	mymap["abc2"]  = 3;
	mymap["abc3"]  = 4;
	mymap["abc4"]  = 5;
	mymap["abc5"]  = 6;
	
	/// the pairs are printed in an unknown order
	for (unordered_map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
		cout << "Key: " << it->first << "\tValue: " << it->second << endl;
	}
	
	map<string, int> mymap2;
	mymap2["abc"]  = 1;
	mymap2["abc1"]  = 2;
	mymap2["abc2"]  = 3;
	mymap2["abc3"]  = 4;
	mymap2["abc4"]  = 5;
	mymap2["abc5"]  = 6;
	
	// the pairs are printed in the sorted order of keys
	for (map<string, int>::iterator it = mymap2.begin(); it != mymap2.end(); it++) {
		cout << "Key: " << it->first << "\tValue: " << it->second << endl;
	}
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	
	// find---> this fn returns an iterator
	if (mymap.find("abc") == mymap.end()) {
		cout << "NOT PRESENT" << endl;
	} else {
		cout << "PRESENT" << endl;	
	}
	
	unordered_map<string, int>::iterator it = mymap.find("abc");
	mymap.erase(it);
		if (mymap.find("abc") == mymap.end()) {
		cout << "NOT PRESENT" << endl;
	} else {
		cout << "PRESENT" << endl;	
	}
	
//  erase the complete map	
//	mymap.erase(mymap.begin(), mymap.end());
	
	for (auto it = mymap.begin(); it != mymap.end(); it++) {
		cout << "Key: " << it->first << "\tValue: " << it->second << endl;
	}
	
	return 0;
}
