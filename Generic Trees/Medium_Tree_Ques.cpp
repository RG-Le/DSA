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

void print_k_level(TreeNode<int> *root, int k) {
	if (root == NULL) return; // EDGE CASE
	if (k == 0) {
		cout << root->data << endl;
		return;
	}
	for (int i = 0; i < root->children.size(); i++) {
		print_k_level(root->children[i], k-1);
	}
}

// RECURSIVE APPROACH 1
int count_leaf(TreeNode<int> *root) {
	if (root == NULL) return 0; // EDGE CASE
	if (root->children.size() == 0) return 1;
	int ans = 0;
	for (int i = 0; i < root->children.size(); i++) {
		ans += count_leaf(root->children[i]);
	}
	return ans;
}

// RECURSIVE APPROACH 2
void count_leaf2(TreeNode<int> *root, int &ans) {
	if (root == NULL) return; // EDGE CASE
	if (root->children.size() == 0){
		ans++;
		return;
	}
	int count = 0;
	for (int i = 0; i < root->children.size(); i++) {
		count_leaf2(root->children[i], ans);
	}
}

int main() {
	TreeNode<int> *root = level_wise_Input();
	cout << endl;
	level_print(root);
	cout << endl;
	cout << "Enter the level to be printed: ";
	int k;
	cin >> k;
	print_k_level(root, k);
	cout << endl;
	int TLN = 0;
	count_leaf2(root, TLN);
	cout << "Number of Leaf Nodes: " << TLN << endl;
//	cout << "Number of Leaf Nodes: " << count_leaf2(root) << endl;
	cout << endl;
	return 0;
}
