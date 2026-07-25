#include <iostream>
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

class list {
public:
    node* head;
    node* tail;

    list() {
        head=tail=NULL;
    }
};

list addtwonumbers(list l1, list l2) {
    list l3;
    node* ptr1 = l1.head;
    node* ptr2 = l2.head;
    int carry=0;
    
    while (ptr1!=NULL || ptr2!=NULL) {
        int sum = ptr1->data + ptr2->data + carry;

        int digit = sum%10;
        carry=sum/10;
        node* newnode = new node(digit);

        if (l3.head==NULL) {
            l3.head=l3.tail=newnode;
        }
        else {
            l3.tail->next = newnode;
            l3.tail = newnode;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    if (carry>0) {
        node* newnode = new node(carry);
        l3.tail->next = newnode;
        l3.tail = newnode;
    }
    return l3;
}

int main() {
    list l1;
    l1.head = new node(3);
    l1.head->next = new node(4);
    l1.head->next->next = new node(7);

    list l2;
    l2.head = new node(5);
    l2.head->next = new node(6);
    l2.head->next->next = new node(7);

    list ans = addtwonumbers(l1, l2);
    node* ptr = ans.head;
    while (ptr!=NULL) {
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    return 0;
}