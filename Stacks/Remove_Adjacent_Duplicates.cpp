#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string A) {
         stack<char> s;
         for(int i=0;i<A.size();i++){
             if(s.empty() || A[i] != s.top()){
                 s.push(A[i]);
             } else {
                 s.pop();
             }
         }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;  
}

// USING INPLACE STACK
string removeDuplicates1(string A) {
	int stptr = -1;
	for(int i=0;i<A.size();i++){
        if(stptr == -1 || A[i] != A[stptr]){
            stptr++;
            A[stptr] = A[i];
        } else {
            stptr--;
        }
    }
	string ans = "";
	for (int i = 0; i <= stptr; i++) {
		ans.push_back(A[i]);
	}	
	return ans;
}

int main() {
	string s;
	cin >> s;

	string op = removeDuplicates1(s);
	cout << op << endl;
	
	return 0;
}
