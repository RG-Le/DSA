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

Node *reverse(Node* head) {
	Node *curr = head;
	Node *prev = NULL;
	
	while (curr != NULL) {
		Node *n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
	return prev;
}

int  main() {
	Node *head = takeInput();
	print(head); 
	
	Node *rev_head = reverse(head);
	print(rev_head);
	
	return 0;
}
