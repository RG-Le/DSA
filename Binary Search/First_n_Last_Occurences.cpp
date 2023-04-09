#include <bits/stdc++.h>
using namespace std;

int getFirst(vector<int> &nums, int target) {
	int s = 0;
	int e = nums.size() - 1;
	int ans = -1;
	while (s >= e) {
		int mid = s + (e-s)/2;
		
		if (nums[mid] == target) {
			ans = mid;
			e = mid - 1; // LHS FOR THE FIRST POSITION 
			//return mid;
		} else if (nums[mid] < target) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}

int getLast(vector<int> &nums, int target) {
	int s = 0;
	int e = nums.size() - 1;
	int ans = -1;
	while (s >= e) {
		int mid = s + (e-s)/2;
		
		if (nums[mid] == target) {
			ans = mid;
			s = mid + 1; // RHS FOR THE LAST POSITION 
			//return mid;
		} else if (nums[mid] < target) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}

void searchRange(vector<int> &nums, int target) {
	vector<int> v;	/// vector of size 2 and initialized with -1
	int first = getFirst(nums, target);
	int last = getLast(nums, target);
	cout << first << " " << last;
}	


int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(7);
	v.push_back(8);
	v.push_back(8);
	v.push_back(10);
	int target;
	cin >> target;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	searchRange(v, target);
	
	return 0;
}
