#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
	T *arr;
	int nextIndex;
	int firstIndex;
	int capacity;
	int size;
	
	public:
		Queue() {
			capacity = 5;
			arr = new T[capacity];
			nextIndex = 0;
			firstIndex = -1;
			size = 0;
		}
		
		Queue(int cap) {
			capacity = cap;
			arr = new T[capacity];
			nextIndex = 0;
			firstIndex = -1;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		bool isEmpty() {
			return size == 0;
		}
		
		void push(T ele) {
			if (size == capacity) {
				cout << "Queue Full!!" << endl;
				return;
			}
			arr[nextIndex] = ele;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex++;
			}
			size++;
		}
		
		T front() {
			if (isEmpty()) {
				cout << "Queue is empty!!" << endl;
				return 0;
			}
			return arr[firstIndex];
		}
		
		void pop() {
			if (isEmpty()) {
				cout << "Queue is Empty!!" << endl;
				return;
			}
			firstIndex = (firstIndex+1) % capacity;
			size--;
			if (size == 0) {
				nextIndex = 0;
				firstIndex = -1;
			}
		}
};

int main() {
	Queue<int> q(5);
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	q.push(70);
	
	cout << q.front() << endl;
	q.pop();
	q.pop();
	q.pop();
	cout << q.front() << endl;
	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
	
	q.push(60);
	q.push(70);
	q.push(80);
	
	while (!q.isEmpty()) {
		cout << q.front() << " ";
		cout << "Size: " << q.getSize() << endl;
		q.pop();
	}
	return 0;
}
