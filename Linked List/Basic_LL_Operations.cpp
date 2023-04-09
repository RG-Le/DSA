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

// INSERTING ELEMENTS AT THE TAIL
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

// INSERTING THE ELEMENTS AT HEAD
// TAKING THE LINKED LIST IN A REVERSE ORDER
Node* takeInput2() {
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
			n->next = head;
			head = n;	
		}
		
		cin >> data;
	}
	return head;
}

// PRINTING A LL
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

//	LENGTH OF A LL
int length(Node* head) {
	int count = 0;
	Node* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

int main() {
	Node *head = takeInput();
	print(head);
	cout << "Length: " << length(head) << endl;
	return 0;
}
