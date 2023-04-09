#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node {
	public:
		T data;
		Node<T> *next;
		
		Node(T data) {
			this->data = data;
			next = NULL;
		}
};

template <typename T>
class Stack {
	Node<T> *head;
	int size;
	
	public:
		
		Stack() {
			head = NULL;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		bool isEmpty() {
			return size == 0;
		}
		
		void push(T data) {
			Node<T> *n = new Node<T>(data);
			n->next = head;
			head = n;
			size++;
		} 
		
		void pop() {
			Node<T>* temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
			size--;
		}
		
		T top() {
			if (isEmpty()) {
				cout << "Stack is Empty!!!" << endl;
				return 0;
			}
			return head->data;
		}
};

int main() {
	Stack<char> s;
	s.push(100);
	s.push(102);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);
	
	cout << s.top() << endl;
	s.pop();
	
	cout << s.top() << endl;
	s.pop();
	
	cout << s.top() << endl;
	s.pop();
	
	cout << s.getSize() << endl;
	cout<< s.isEmpty() << endl;
	return 0;
}
