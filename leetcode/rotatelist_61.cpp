#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data=x;
        next=nullptr;
    }
};

node* rotateright(node* head, int k) {
    if (k==0) return head;
    if (head==nullptr) return nullptr;

    int n = 0;
    node* temp = head;
    node* tail = head;
    while (temp!=nullptr) {
        n++;
        temp = temp->next;
    }

    while (tail->next!=nullptr) {
        tail=tail->next;
    }

    k=k%n;

    if (k==0) return head;

    int pos = n-k;
    int n1 = 1;
    node* newtail = head;
    while (n1<pos) {
        newtail = newtail->next;
        n1++;
    }
    node* newhead = newtail->next;

    tail->next = head;
    newtail->next = nullptr;
    head = newhead;
    

    return head;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    node* newhead = rotateright(head, 2);

    node* temp = newhead;
    while (temp!=nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}
