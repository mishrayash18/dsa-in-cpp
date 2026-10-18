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

node* reverselltwo(node* head, int left, int right) {
    if (head==nullptr) return nullptr;

    int count1 = 1;
    node* start = head;
    node* startprev = nullptr;

    while (count1<left) {
        startprev = start;
        start=start->next;
        count1++;
    }

    int count2 = 1;
    node* end = head;

    while (count2<right) {
        end=end->next;
        count2++;
    }

    node* endnext = end->next;


    node* prev = nullptr;
    node* curr = start;
    while (curr!=endnext) {
        node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    if (startprev != nullptr) {
        startprev->next = prev;
    }
    else {
        head = prev;
    }
    start->next = endnext;
    
    return head;
}

