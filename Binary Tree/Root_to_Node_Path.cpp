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

bool getPath(BTNode<int> *root, int key, vector<int> &v) {
	if (root == NULL) return false;
	
	v.push_back(root->data);
	
	if (root->data == key) return true;
	
	bool left = getPath(root->left, key, v);
	bool right = getPath(root->right, key, v);
	
	if (left || right) return true;
	
	v.pop_back();
	return false;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BTNode<int> *root = level_input();
	level_print(root);
	
	vector<int> v;
	int key;
	cout << "Enter the key to search its path: ";
	cin >> key;
	cout << endl;
	
	if (getPath(root, key, v)) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << "->";
		}
		cout << "END" << endl;
	} else {
		cout << "No Path Found!!! (Value Does Not Exist)" << endl;
	}
	
	return 0;
}
