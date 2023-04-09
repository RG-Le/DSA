#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
     int data;
     Node *next;

     Node(int data){
       this->data = data;
       next = NULL;
     }
};

Node* takeInput(){
   int data;
   cin>>data;
   Node *head = NULL;  /// LL is empty
   Node *tail = NULL;   /// LL is empty
   while(data != -1){
    /// creating LL
    Node *n = new Node(data);
    /// 1st node
    if(head == NULL){
        head = n;
        tail = n;
    }else {
        tail -> next = n;   /// Inserting at Tail
        tail = n;
    }

    cin>>data;
   }
   return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool countOcc(int k, vector<int> a) {
	int count = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == k) {
			count++;
		}
		if (count > 1) {
			return false;
		}
	}
	return true;	
}

void detectCycle(Node *head) {
	Node *curr = head;
	bool a = true;
	vector<int> v;
	v.push_back(curr->data);
	while (a || curr->next == NULL) {
		curr = curr->next;
		v.push_back(curr->data);
		if (!countOcc(curr->data, v)) {
			cout << "Cycle Detected!!!" << endl;
			a = false;
		} 
	}
	
	if (a == false) {
		cout << "NO CYCLE!!!" << endl;
	}
	
}

int main() {
	Node *head = takeInput();
	print(head);
	detectCycle(head);
	return 0;
}
