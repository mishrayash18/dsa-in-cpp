#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        next = nullptr;
    }
};

node* removeDuplicates(node* head) {
    node* temp = head;
    
    if (head == nullptr) {
        return head;
    }

    while (temp->next!=nullptr) {
        if (temp->data == temp->next->data) {
            temp -> next = temp -> next -> next;
        }
        else{
            temp = temp -> next;
        }
        
    }
    return head;
}

int main() {
    node* head = new node(1);
    head->next = new node(1);
    head->next->next = new node(2);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(3);

    head = removeDuplicates(head);

    node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}