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

void print_ith(Node* head, int i) {
	if (head == NULL) {
		cout << "NODE NOT FOUND!!!" << endl;
		return;
	}
	
	int count = 0;
	Node* temp = head;
	
	while (temp != NULL) {
//		count++;
		if (count == i) {
			cout << temp->data << endl;
			return;
		}
		temp = temp->next;
		count++;
	}
	cout << "NODE NOT FOUND!!!" << endl;
}

Node* input_ith(Node* head, int i, int data) {
	if (head == NULL) {
		Node* n = new Node(data);
		n->next = NULL;
		head = n;
		return head;
	}
	
	if (i == 0) {
		Node* temp = new Node(data);
		Node* n = new Node(data);
		n->next = head;
		head = n;
		return head;
	}	
	
	int count = 0;
	Node *temp = head;
	while (temp != NULL) {		
		if (i - 1 == count) {
			Node* n = new Node(data);
			n->next = temp->next;
			temp->next = n;
			return head;
		}
		
		count++;
		temp = temp->next;
	}
	
	return head;
	
}

Node *delete_ith(Node *head, int i) {
	if (head == NULL) {
		cout << "NULL LL!!";
	}
	
	if (i == 0) {
		Node* temp = head;
		head = temp->next;
		delete temp;
		return head;
	}
	
	Node *temp = head;
	int count = 0;
	
	while (temp != NULL) {
		if (i - 1 == count) {
			Node* temp2 = temp->next;
			temp->next = temp->next->next;
			temp2->next = NULL;
			delete temp2;	
		}
		count++;
		temp = temp->next;
	}
	return head;
}

Node *remove_nth_from_end(Node *head, int k) {
	Node *one = head;
	Node *two = head;
	
	while (k--) {
		two = two->next;
	}
	
	if(two == NULL) {// Length of LL = k --> delete the head
		return one->next;	
	}
	
	while (two->next != NULL) {
		one = one->next;
		two = two->next;
	}
	
	one->next = one->next->next;
	
	return head;
}

int main() {
	Node *head = takeInput();
	print(head);
	int i; 
	cin >> i;
//	print_ith(head, i);
//	head = input_ith(head, i, 20);
//	print(head);
//	head = delete_ith(head, i);
//	print(head);
	head = remove_nth_from_end(head, i);
	print(head);
	return 0;
}
