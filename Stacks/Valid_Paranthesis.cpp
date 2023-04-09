#include <bits/stdc++.h>
using namespace std;

bool validPar(string A) {
	stack<char> s;
        
        for(int i=0;i<A.size();i++){
            
            if(A[i]=='(' || A[i]=='{' || A[i]=='['){
                s.push(A[i]);
            } else{
                
                if(s.empty()) return false; /// imp otherwise run time erro
                else if(A[i]==')'){
                    if(s.top() == '(') s.pop();
                    else return false;
                }else if(A[i]=='}'){
                    if(s.top() == '{') s.pop();
                    else return false;
                }else if(A[i]==']'){
                    if(!s.empty() && s.top() == '[') s.pop();
                    else return false;
                }
                
            }
            
        }
        
        if(s.empty()) return true;
        
        return false;
} 

int main() {
	string s = "([]{}[])";
	
	if (validPar(s) == true) {
		cout << "Valid Paranthesis" << endl;
	} else {
		cout << "Invalid Paranthesis" << endl;
	}
	return 0;
}
