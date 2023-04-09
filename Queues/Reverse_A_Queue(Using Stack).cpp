#include <bits/stdc++.h>
using namespace std;

void rev(queue<int> &q) {
	stack<int> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}
}

int main() {
	queue<int> q;
	for (int i = 0; i < 6; i++) {
		q.push(i);
	}
	rev(q);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
