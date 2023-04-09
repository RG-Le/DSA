/// INTERSECTION OF 2 ARRAYS
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	vector<int> nums1;
	nums1.push_back(4);
	nums1.push_back(9);
	nums1.push_back(5);
				
	vector<int> nums2;
	nums2.push_back(9);
	nums2.push_back(4);
	nums2.push_back(9);
	nums2.push_back(8);
	nums2.push_back(4);
		
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < nums2.size(); i++) {
		cout << nums2[i] << " ";
	}
	cout << endl;
	
	
	sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
        
    for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}    
    cout << endl;
	
	for (int i = 0; i < nums2.size(); i++) {
		cout << nums2[i] << " ";
	}
	 
	cout << endl;
	   
    vector<int> ans;
        
    int i, j = 0;
        
        while (i < nums1.size() || j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                j++;
            }
            
            if (nums1[i] < nums2[j]) {
                i++;
            }
            
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;j++;
            }
        }
        
        for (int i = ans.size() - 1; i >= 1; i--) {
            if (ans[i] == ans[i - 1]) {
                ans.pop_back();
            }
        }
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
