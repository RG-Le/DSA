#include <iostream>
#include <vector>
using namespace std;

// DFS print method for connected graph
void print(vector<vector<int> > v, int sv, vector<bool> &visited) {
	cout << sv << endl;
	visited[sv] = true;
	int n = v.size();
	for(int i = 0; i < n; i++) {
		if(v[sv][i] == 1 && visited[i] == false) {
			print(v, i, visited);
		}
	}
}

///DFS for disconnected graph
void DFS(vector<vector<int> > matrix) {
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
	
	cout << "DFS Print" << endl;
	DFS(matrix);
	
	return 0;
}
