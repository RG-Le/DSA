#include <bits./stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens) {
	stack<int> st;
	
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int e1 = st.top();
			st.pop();
			int e2 = st.top();
			st.pop();
			
			if (tokens[i] == "+") {
				st.push(e2 + e1);
			}else if (tokens[i] == "-") {
				st.push(e2 - e1);
			}else if (tokens[i] == "*") {
				st.push(e2 * e1);
			}if (tokens[i] == "/") {
				st.push(e2 / e1);
			}
		} else {
			st.push(atoi(tokens[i].c_str()));
		}
	}
	return st.top();
}

int main() {
	vector<string> s;
	s = {"4", "13", "5", "/", "+"};
	vector<string> s1;
	s1 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << evalRPN(s) << endl;
	cout << evalRPN(s1) << endl;
	return 0;
}
