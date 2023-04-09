#include <bits/stdc++.h>
using namespace std;

// to make class generic
// template <typename T>
// make changes accordingly;
// int *arr -> T *arr
// 

class Stack {
	int *arr;
	int nextIndex; 
	int capacity;
	
	public:
		
		Stack() {
			capacity = 10;
			arr = new int[capacity];
			nextIndex = 0;
		}
				
		int size() {
			return nextIndex;
		}
		
		bool isEmpty() {
			return nextIndex == 0;
		}
		
		void push(int data) {
			if (nextIndex == capacity) {
				int *newArr = new int[2*capacity];
				for (int i = 0; i < capacity; i++) {
					newArr[i] = arr[i];
				}
				delete []arr;
				arr = newArr;
			}
			arr[nextIndex] = data;
			nextIndex++;
			capacity = 2*capacity;
		}
		
		void pop() {
			if (isEmpty()) {
				cout << "Stack is Empty!!" << endl;
				return;
			}
			nextIndex--;
		}
		
		int top() {
			if (isEmpty()) {
				cout << "Stack is Empty!!" << endl;
				return -1;
			}
			return arr[nextIndex - 1];
		}
};

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	cout << s.top() << endl;
	s.pop();
	
	cout << s.top() << endl;
	s.pop();
	
	cout << s.size() << endl;
	cout << s.isEmpty() << endl;
	
	return 0;
}
