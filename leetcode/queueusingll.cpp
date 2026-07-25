#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data=val;
        next=NULL;
    }
};

class queue {
public:
    node* head;
    node* tail;

    queue() {
        head=tail=NULL;
    }

    void push(int val) {
        node* newnode= new node(val);
        if (head==NULL) {
            head=tail=newnode;
        }
        else {
            tail->next=newnode;
            tail=newnode;
        } 
    }

    void pop() {
        if (head==NULL) {
            cout << "XX queue is empty XX\n"; 
        }
        else {
            head = head->next;
        }
    }

    void front() {
        if (head == NULL) {
            cout << "XX queue is empty\n";
        }
        else {
            cout << head->data << endl;
        }
    }
};

int main() {
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.front();
    q.pop();
    q.front();
    return 0;
}