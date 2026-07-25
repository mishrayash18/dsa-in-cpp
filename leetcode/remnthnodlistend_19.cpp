#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node (int data) {
        this->data=data;
        next=NULL;
    }
};

class list {
public:
    node* head;

    list() {
        head = NULL;
    }

    void insert(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next = newnode;
    }

    void display() {
        if (head == NULL) {
            cout << "list is empty\n";
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    node* remnthnodlistend(node* head, int n) {
        int count = 0;
        node* temp = head;
        
        while (temp!=NULL) {
            count++;
            temp=temp->next;
        }

        int rempos = count-n;
        int track = 0;

        if (rempos == 0) {
            node* newhead = head;
            delete(head);
            return newhead;
        }

        node* str = head;
        while (track!=rempos-1) {
            str = str->next;
            track++;
        }
        str->next = str->next->next;

        return head;
    }
};

int main() {
    list ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.remnthnodlistend(ll.head, 2);
    ll.display();
    return 0;
}