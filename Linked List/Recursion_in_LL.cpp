#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node *next;
	
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

Node *takeInput() {
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1) {
		Node *n = new Node(data);
		
		if (head == NULL) {
			head = n;
			tail = n;
		} else {
			tail->next = n;
			tail = n;	
		}
		
		cin >> data;
	}
	return head;
}

void print(Node *head) {
	if (head == NULL) {
		return ;
	}
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL"  << endl;
}

int length_rec(Node* head) {
	if (head == NULL) {
		return 0;
	}
	
	return 1 + length_rec(head->next);
}

bool search(Node* head, int data) {
	if (head == NULL) return false;
	
	if (head->data == data) {
		return true;
	} else {
		search(head->next, data);
	}
}

int main() {
	Node *head;
	head = takeInput();
	print(head);
//	cout << "Length: " << length_rec(head);
	int data;
	cin >> data;
	if (search(head, data)){
		cout << "ELement is present" << endl;
	} else {
		cout << "Element is not present" << endl;
	}
	return 0;
}
