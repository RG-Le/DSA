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

// inorder traversal---> Left Root Right
void inorder(BTNode<int> * root) {
	if (root == NULL) return;
	
//	if (root->left) {
//		inorder(root->left);
//	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
//	if (root->right) {
//		inorder(root->right);
//	}
}

// preorder traversal---> Root Left Right
void preOrder(BTNode<int> *root) {
	if (root == NULL) return;
	
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

// postorder---> Left Roght Root 
void postOrder(BTNode<int> *root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

// ip tree
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main() {
	BTNode<int> *root = level_input();
	level_print(root);
	cout << endl;
	cout << "Inorder Print: ";
	inorder(root);
	cout << endl;
	cout << "PreOrder Print: ";
	preOrder(root);
	cout << endl;
	cout << "PostOrder Print: ";
	postOrder(root);
	cout << endl;
	return 0;
}
