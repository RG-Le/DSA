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

Node *mid_node(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	
	Node *slow = head;
	Node *fast = head->next;
	
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if (fast != NULL) return slow->next;
	return slow;
}

int  main() {
	Node *head = takeInput();
	print(head); 
	Node *mid = mid_node(head);
	cout << mid->data << endl;
	return 0;
}
