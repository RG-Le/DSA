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

BTNode<int> *helper(vector<int> inOrder, vector<int> postOrder, int INS, int INE, int PostS, int PostE) {
	if (INS > INE) {
		return 0; // REPLACE 0 WITH NULL IN LEETCODE
	}	
	
	int rootData = postOrder[PostE];
	
	int rootIndex = -1;
	for (int i = INS; i <= INE; i++) {
		if (inOrder[i] == rootData) {
			rootIndex = i;
			break;
		}
	}
	
	int leftINS = INS;
	int leftINE = rootIndex - 1;;
	int leftPostS = PostS;
	int leftPostE = leftINE - leftINS + leftPostS;
	
	int rightINS = rootIndex + 1;
	int rightINE = INE;
	int rightPostS = leftPostE + 1;
	int rightPostE = PostE - 1;
	
	BTNode<int> *root = new BTNode<int>(rootData);
	root->left = helper(inOrder, postOrder, leftINS, leftINE, leftPostS, leftPostE);
	root->right = helper(inOrder, postOrder, rightINS, rightINE, rightPostS, rightPostE);
}

/// SOLVED IN LEETCODE
BTNode<int> *buildTree(vector<int> &postOrder, vector<int> &inOrder) {
	int n = inOrder.size();
	return helper(inOrder, postOrder, 0, n - 1, 0, n-1);
}


int main() {
	vector<int> postorder = {9,15,7,20,3};
	vector<int> inorder = {9,3,15,20,7};
	
	BTNode<int> *root = buildTree(postorder, inorder);
	level_print(root);
	
	return 0;
}
