#include  <bits/stdc++.h>
using namespace std;

template <typename T>
class BTNode{
	public:
		T data;
		BTNode<T> *left;
		BTNode<T> *right;
		
		BTNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL; 
		}
		
		~BTNode() {
			delete left;
			delete right;
		}
};

void level_print(BTNode<int> *root) {
	queue<BTNode<int>*> q;
	q.push(root);
	
	while(!q.empty()) {
		BTNode<int> *f = q.front();
		q.pop();
		
		cout << f->data << ": ";
		
		if (f->left) {
			cout << "L" << f->left->data << " ";
			q.push(f->left);	
		}
		
		if (f->right) {
			cout << "R" << f->right->data << " ";
			q.push(f->right);	
		}
		
		cout << endl; 
	}
}

BTNode<int> *helper(vector<int> inOrder, vector<int> preOrder, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return 0;/// REPLACE 0 WITH NULL IN LEETCODE 
	}
	int rootdata = preOrder[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (inOrder[i] == rootdata) {
			rootIndex = i;
			break;
		}
	}
	
	// leftINE - leftINS = leftPreE - leftPreS
	// number of elements in a same tree
	int leftINS = inS;
	int leftINE = rootIndex - 1;
	int leftPreS = preS + 1;
	int leftPreE = leftPreS + leftINE - leftINS;
	
	int rightINS = rootIndex + 1;
	int rightINE = inE;
	int rightPreS = leftPreE + 1;
	int rightPreE = preE;
	
	BTNode<int> *root = new BTNode<int>(rootdata);
	root->left = helper(inOrder, preOrder, leftINS, leftINE, leftPreS, leftPreE);
	root->left = helper(inOrder, preOrder, rightINS, rightINE, rightPreS, rightPreE);
}

/// SOLVED IN LEETCODE
BTNode<int> *buildTree(vector<int> &preorder, vector<int> &inorder) {
	int n = inorder.size();
	return helper(inorder, preorder, 0, n - 1, 0, n - 1);
}


int main() {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	
	BTNode<int> *root = buildTree(preorder, inorder);
	level_print(root);
	
	return 0;
}
