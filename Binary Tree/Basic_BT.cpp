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

void rec_print(BTNode<int> *root) {
	if (root == NULL) {// BASE CASE
		return;
	}
	
	cout << root->data << ": ";
	
	if (root->left != NULL) {
		cout << "L" << root->left->data << " ";
	}
	
	if (root->right != NULL) {
		cout << "R" << root->right->data << " ";
	}
	cout << endl;
	
	rec_print(root->left);
	rec_print(root->right);
}

BTNode<int> *rec_input() {
	int data;
	cout << "Enter Data: " << endl;
	cin >> data;
	
	if (data == -1) {// base case
		return NULL;
	}
	
	BTNode<int> *root = new BTNode<int>(data);
	BTNode<int> *leftChild = rec_input();
	BTNode<int> *rightChild = rec_input();
	
	root->left = leftChild;
	root->right = rightChild;
	
	return root;
}

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

int countNodes(BTNode<int> *root) {
	if (root == NULL) return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

// ip tree
//  1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
int main() {
	BTNode<int> *root = level_input();
	level_print(root);
	cout << "Total Nodes: " << countNodes(root);
	return 0;
}
