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

// recursive print is the preorder traversal
// first print root then the children
void preOrder_print(TreeNode<int> *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	
	for (int i = 0; i < root->children.size(); i++) {
		preOrder_print(root->children[i]);
	}
}

// post order traversal;
// first print the children then the root
void postOrder_print(TreeNode<int> *root) {
	if (root == NULL) return;
	
	for (int i = 0; i < root->children.size(); i++) {
		postOrder_print(root->children[i]);
	}
	
	cout << root->data << " ";
}

int main() {
	TreeNode<int> *root = level_wise_Input();
	cout << endl;
	level_print(root);
	cout << endl;
	cout << "The pre order print is:" << endl;
	preOrder_print(root);
	cout << endl;
	cout << "The post order print is: " <<endl;
	postOrder_print(root);
	cout << endl;
	return 0;
}
