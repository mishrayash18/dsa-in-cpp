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

node* removeElements(node* head, int val) {
    node* temp = head;

    if (head == nullptr) return head;

    while (head!=nullptr && head->data == val) {
        head = head->next;
    }

    while (temp->next!=nullptr) {
        if (temp->next->data == val) {
            temp->next = temp->next->next;
        }
        else {
            temp=temp->next;
        } 
    }

    return head;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(4);

    node* newhead = removeElements(head, 2);

    node* temp = newhead;
    while (temp!=nullptr) {
        cout << temp->data << endl;
        temp=temp->next;
    }
    return 0;
}