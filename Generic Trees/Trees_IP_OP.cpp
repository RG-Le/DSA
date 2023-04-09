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
		
		~TreeNode() {
			for (int i = 0; i < children.size(); i++) {
				delete children[i];
			}
		}
};

void print(TreeNode<int> *root) {
	if (root == NULL) return; // not a case case
	// base case are leaf nodes!!!
	cout << root->data << ": ";
	
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << " ,";
	}
	cout << endl;
	
	for (int i = 0; i < root->children.size(); i++) {
		print(root->children[i]);
	}
} 

/// RECURSIVE INPUT
TreeNode<int> *takeInput() {
	int rootData;
	cout << "Enter Data: " << endl;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	
	// How many children
	int n;
	cout << "Enter number of children of " << rootData << endl;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
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

int main() {
	TreeNode<int> *root = level_wise_Input();
	print(root);
	level_print(root);
	return 0;
}
