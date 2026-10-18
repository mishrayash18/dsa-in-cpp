#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data=x;
        next=nullptr;
    }
};

node* oddevenlist(node* head) {
    if (head==nullptr) return nullptr;

    node* odd = head;
    node* even = head->next;
    node* temp = even;

    while (even!=nullptr && even->next!=nullptr) {
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even=even->next;
    }

    odd->next = temp;

    return head;

}