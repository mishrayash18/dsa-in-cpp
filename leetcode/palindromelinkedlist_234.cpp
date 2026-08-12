#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    node* next;

    node(int x) {
        data=x;
        next=nullptr;
    }
};

bool isPalindrome(node* head) {
    stack<int> result;

    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    node* slow = head;
    node* fast = head;

    // Find middle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Push first half into stack
    node* temp = head;

    while (temp != slow) {
        result.push(temp->data);
        temp = temp->next;
    }

    // Odd length: skip the middle node
    if (fast != nullptr) {
        slow = slow->next;
        temp = slow;
    }

    // Compare second half with stack
    while (temp != nullptr) {
        if (result.empty() || temp->data != result.top()) {
            return false;
        }

        result.pop();
        temp = temp->next;
    }

    return result.empty();
}
int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(2);
    head->next->next->next = new node(1);

    cout << isPalindrome(head);
}