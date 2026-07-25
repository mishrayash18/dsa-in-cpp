#include <iostream>
#include <vector>
#include <list>
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

class stack {
    list <int> ll;
public:
    node* head;
    node* tail;

    void push(int val) {
        ll.push_front(val);
    }

    void pop() {
        ll.pop_front();
    }

    int top() {
        return ll.front();
    }

    bool empty() {
        return ll.size()==0;
    }
};

int main() {
    stack s;
    s.push(109);
    s.push(110);
    s.push(111);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}