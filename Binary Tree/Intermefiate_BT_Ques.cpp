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

BTNode<int> *level_input() {
	int rootData;
	cout << "Enter root data: ";
	cin >> rootData;
	cout << endl;
	BTNode<int> *root = new BTNode<int>(rootData);
	queue<BTNode<int>*> q;
	q.push(root);
	
	while (!q.empty()) {
		BTNode<int> *f = q.front();
		q.pop();
		
		int leftChildData;
		cout << "Enter Left Child Data of " << f->data << ": ";
		cin >> leftChildData;
		cout << endl;
		if (leftChildData != -1) {
			BTNode<int> *leftChild = new BTNode<int>(leftChildData);
			q.push(leftChild);
			f->left = leftChild;			
		}

		int rightChildData;
		cout << "Enter Right Child Data of " << f->data << ": ";
		cin >> rightChildData;
		cout << endl;
		if (rightChildData != -1) {
			BTNode<int> *rightChild = new BTNode<int>(rightChildData);
			q.push(rightChild);
			f->right = rightChild;
		}
	}
	return root;
}

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

/// height or max depth
int height(BTNode<int> *root) {
	if (root == NULL) return 0;
	
	int leftH = height(root->left);
	int rightH = height(root->right);
	
	return max(leftH, rightH) + 1;
}

/// SYMMETRIC TREE CHECK
bool helper(BTNode<int> *leftTree, BTNode<int> *rightTree) {
	if (leftTree == NULL && rightTree == NULL) return true;
	if (leftTree == NULL && rightTree != NULL) return false;
	if (leftTree != NULL && rightTree == NULL) return false;
	if (leftTree->data != rightTree->data) return false;
	
	return helper(leftTree->left, rightTree->right) && helper(leftTree->right, rightTree->left);
}

bool isSymmetric(BTNode<int> *root) {
	if (root == NULL) return true;
	return helper(root->left, root->right);
}

// FIND NODE
bool find(BTNode<int> *root, int key) {
	if (root == NULL) return false;
	
	if (root->data == key) {
		return true;
	} 
	
	return find(root->left, key) || find(root->right, key);
}


// minimum value in a BT
int minVal(BTNode<int> *root) {
	if (root == NULL) return INT_MAX;
	
	int ans = root->data;
	int leftMin = minVal(root->left);
	int rightMin = minVal(root->right);
	
	return min(ans, min(leftMin, rightMin));
}

// other approach
void minVal2(BTNode<int> *root, int &ans) {
	if (root == NULL) return;
	ans = min(ans, root->data);
	minVal2(root->left, ans);
	minVal2(root->right, ans);
}

// maximum value in a BT
int maxVal(BTNode<int> *root) {
	if (root == NULL) return INT_MIN;
	
	int ans = root->data;
	int leftMax = maxVal(root->left);
	int rightMax = maxVal(root->right);
	
	return max(ans, max(leftMax, rightMax));
}

// other approach
void maxVal2(BTNode<int> *root, int &ans) {
	if (root == NULL) return;
	ans = max(ans, root->data);
	maxVal2(root->left, ans);
	maxVal2(root->right, ans);
}


/// total number of leaf nodes in a BT
int countLeaf(BTNode<int> *root) {
	if (root == NULL) return 1;
	
	// CONDITION FOR A LEAF NODE
	if (root->left == NULL && root->right == NULL) return 1;
	
	int leftLeaf = countLeaf(root->left);
	int rightLeaf = countLeaf(root->right);
	
	return leftLeaf + rightLeaf;
}

// other approach
void countLeaf2(BTNode<int> *root, int &ans) {
	if (root == NULL) return;
	
	if (root->left == NULL && root->right == NULL) {
		ans++;
		return; // optional
	}
	
	countLeaf2(root->left, ans);
	countLeaf2(root->right, ans);
}

// ip tree
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main() {
	BTNode<int> *root = level_input();
	level_print(root);
	cout << endl;
	cout << "Height or Max Depth: " << height(root) << endl;
	cout << "Symmetric: " << isSymmetric(root) << endl;
	cout << "Exists 9: " << find(root, 9) << endl;;
	cout << "Minimum Value: ";
	int mnVal = INT_MAX;
	minVal2(root, mnVal);
	cout << mnVal << endl;
	cout << "Minimum Value: " << minVal(root) << endl;
	cout << "Maximum Value: ";
	int mxVal = INT_MIN;
	maxVal2(root, mxVal);
	cout << mxVal << endl;
	cout << "Maximum Value: " << maxVal(root) << endl;
	cout << "Numbr of leaf Nodes: " << countLeaf(root) << endl;
	int count = 0;
	cout << "Number of Leaf Node: ";
	countLeaf2(root, count);
	cout << count << endl;
	return 0;
}
