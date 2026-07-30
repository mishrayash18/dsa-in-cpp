#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

// // BRUTE FORCE [O(m*n)]
// node* getIntersectionNode(node* headA, node* headB) {
//     node* tempA = headA;
//     node* tempB = headB;
//     while (tempA!=nullptr) {
//         while (tempB!=nullptr){
//             if (tempA == tempB ) {
//                 return tempA;
//             }
//             tempB=tempB->next;
//         }
//         tempA=tempA->next;
//         tempB=headB;
//     }
//     return nullptr;
// }


// OPTIMISED [O(m+n)]
node* getIntersectionNode(node* headA, node* headB) {
    node* tempA = headA;
    node* tempB = headB;
    while (tempA!=tempB) {
        if (tempA == nullptr) {
            tempA = headB;
        }
        else {
            tempA = tempA -> next;
        }
        if (tempB == nullptr) {
            tempB = headA;
        }
        else {
            tempB = tempB -> next;
        }
    }
    return tempA;
}
int main() {
    node* headA = new node(10);
    headA -> next = new node(20);
    headA -> next -> next = new node(30);

    node* headB = new node(40);
    headB -> next = new node(50);
    headB -> next -> next = headA -> next -> next;

    node* ans = getIntersectionNode(headA, headB);
    cout << ans->data;
}