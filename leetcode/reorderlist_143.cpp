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

void reorderList(node* head) {
    if (head==nullptr) return;

    node* slow = head;
    node* fast = head;

    while (fast!=nullptr && fast->next!=nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    node* curr = slow;
    node* prev = nullptr;
    while (curr!=nullptr) {
        node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    node* p1 = head;
    node* p2 = prev;;

    while (p1!=p2 && p1->next!=p2) {
        node* next1 = p1->next;
        node* next2 = p2->next;

        p1->next = p2;
        p2->next = next1;

        p1 = next1;
        p2 = next2;
    }

}