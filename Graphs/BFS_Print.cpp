#include <iostream>
#include <queue>
using namespace std;

void print(vector<vector<int> > v, int sv, vector<bool> &visited) {
	// its important to pass visited array/vector by reference
	// since the value of visited array changes continously
	int n = v.size();
	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	
	while(!q.empty()) {
		int cv = q.front();
		q.pop();
		cout << cv << endl;
		for(int i = 0; i < n; i++) {
			if(v[cv][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS(vector<vector<int> > matrix) {
	int n = matrix.size();
	vector<bool> visited(n, false);
	int count = 0;
	for (int i = 0; i < n; i++){
		if (!visited[i]) {
			print(matrix, i, visited);
			count++;
		}
	}
	cout << "The number of connected components = " << count << endl;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int> > matrix(n, vector<int>(n, 0));
	// Input using ajacency matrix
	for (int i = 1; i<= e; i++) {
		int fv, sv;
		cin >> fv >> sv;
		matrix[fv][sv] = 1;
		matrix[sv][fv] = 1;
	}
	
	cout << "BFS Print" << endl;
	BFS(matrix);
	
	return 0;
}
