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

Node *merge(Node *head1, Node *head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	
	Node *finalHead = NULL;
	if (head1->data < head2->data) {
		finalHead = head1;
		head1 = head1->next;
	} else {
		finalHead = head2;
		head2 = head2->next;
	}
	
	Node *p = finalHead; // finalTail pointer
	
	while (head1 && head2) {
		if (head1->data <  head2->data) {
			p->next = head1;
			head1 = head1->next;
		} else {
			p->next = head2;
			head2 = head2->next;
		}
		p = p->next;
	}
	
	if (head1) {
		p->next = head1;
	} else {
		p->next = head2;
	}
	
	return finalHead;
}

Node *merge_rec(Node *l1, Node *l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	
	Node *newHead = NULL;
	
	if (l1->data < l2->data) {
		newHead = l1;
		newHead->next = merge_rec(l1->next, l2);	
	} else {
		newHead = l2;
		newHead->next = merge_rec(l1, l2->next);
	}
	return newHead;
}

int  main() {
	Node *head1 = takeInput();
	print(head1); 
	Node *head2 = takeInput();
	print(head2);
	Node *final_head = merge_rec(head1, head2);
	print(final_head);
	return 0;
}
