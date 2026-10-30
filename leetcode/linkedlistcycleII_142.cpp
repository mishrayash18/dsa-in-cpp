#include <iostream>
#include <unordered_set>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data=x;
        next=nullptr;
    }
};


int detectcycle(node* head) {
    unordered_set<node*> visited;
    node* temp = head;

    while (temp!=nullptr) {

        if (visited.find(temp)!=visited.end()) {
            int pos = 1;
            node* temp1 = head;
            while (temp1!=temp) {
                temp1=temp1->next;
                pos++;
            }
            return pos;
        }
        visited.insert(temp);
        temp=temp->next;
    }

    return -1;

}