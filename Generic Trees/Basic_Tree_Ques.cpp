#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
	public:
		T data;
		vector<TreeNode<T>*> children;
		
		TreeNode(T data) {
			this->data = data;
		}
};

/// LEVEL WISE PRINT
void level_print(TreeNode<int> *root) {
	queue<TreeNode<int>*> q;
	q.push(root);
	
	while (!q.empty()) {
		TreeNode<int> *f = q.front();
		q.pop();
		
		cout << f->data << ": ";
		for (int i = 0; i < f->children.size(); i++) {
			cout << f->children[i]->data << ", ";
			q.push(f->children[i]);
		}
		cout << endl;
	}
}

/// ITERATIVE INPUT (BETTER WAY OF TAKING INPUT!!)
TreeNode<int> *level_wise_Input() {
	int rootData;
	cout << "Enter root data: " << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> q;
	q.push(root);
	
	while (!q.empty()) {
		TreeNode<int> *f = q.front();
		q.pop();
		
		cout << "Enter number of children of " << f->data << endl;
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << f->data << endl;
			cin >> childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			q.push(child);
			f->children.push_back(child);
		}
	}
	return root;
}

// NUMBER OF NODES IN A TREE
int countNodes(TreeNode<int> *root) {
	if (root == NULL) return 0;//EDGE CASE (NOT THE BASE CASE!!)
	int count = 1;
	for (int i = 0; i < root->children.size(); i++) {
		count += countNodes(root->children[i]);
	}
	return count;
}

int height(TreeNode<int> *root) {
	if (root == NULL) return 0; // EDGE CASE (NOT THE BASE CASE!!!)
	int maxH = 0;
	for (int i = 0; i < root->children.size(); i++) {
		int childHeight = height(root->children[i]);
		maxH = max(maxH, childHeight);
//		if (childHeight > max) {
//			max = childHeight;
//		}
	}
	return maxH + 1;
	
}



int main() {
	TreeNode<int> *root = level_wise_Input();
	cout << endl;
	level_print(root);
	cout << endl;
	cout << "Number of Nodes: " << countNodes(root) << endl;
	cout << "Height of the Tree: " << height(root) << endl;
	return 0;
}
