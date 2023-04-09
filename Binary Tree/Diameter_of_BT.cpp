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


int height(BTNode<int> *root) {
	if (root == NULL) return 0;	
	return 1 + max(height(root->left), height(root->right));
}


// DIAMETER APPROACH 1
int diameter(BTNode<int> *root) {
	if (root == NULL) {
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);
	
	return max(op1, max(op2, op3));
}


// DIAMETER APPROACH 2  (BETTER APPROACH!!)
pair<int, int> heightDiameter(BTNode<int> *root) {
	if (root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	
	pair<int, int> leftST = heightDiameter(root->left);
	pair<int, int> rightST = heightDiameter(root->right);
	
	int lh = leftST.first;
	int ld = leftST.second;
	
	int rh = rightST.first;
	int rd = rightST.second;
	
	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh, max(ld, rd));
	
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p; 
}

int diameter2(BTNode<int> *root) {
	pair<int, int> p = heightDiameter(root);
	return p.second;
}


int main() {
	BTNode<int> *root = level_input();
	level_print(root);
	cout << "Diameter or Max Distance between Any 2 Nodes is: " << diameter2(root) << endl;
}
