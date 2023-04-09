#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<string, int> mymap;
	
	// insertion
	// way1-----> using pair class
	pair<string, int> p("abc", 1);
	mymap.insert(p);
	
	// way2-----> like arrays
	mymap["def"] = 2;
	
	// extraction of elements
	cout << mymap["abc"] << endl;
	cout << mymap.at("abc") << endl;
//	cout << mymap.at("ghi") << endl; // throws exception when key is not present
	cout << mymap["ghi"] << endl; //if the key does not exist , default value of 0 is assigned
	
	// chack the presence of a key
	if (mymap.count("ghi") > 0) {
		// count return only 0 or 1 as the key is unique
		cout << "key is present" << endl;
	} else {
		cout << "key not present" << endl;
	}
	
	
	// update
	mymap["abc"] = 20;
	
	// size of the map
	cout << "Size: " << mymap.size() << endl;
	
	// deleting an entry
	mymap.erase("ghi");
	return 0;
}
