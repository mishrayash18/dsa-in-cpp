#include <iostream>
using namespace std;

struct node {
    node* left;
    int data;
    node* right;

    node (int x) {
        left=right=nullptr;
        data=x;
    }
};

bool helper(node* leftnode, node* rightnode) {
    if (leftnode == nullptr && rightnode == nullptr) return true;
    if ((leftnode == nullptr && rightnode != nullptr) || (leftnode != nullptr && rightnode == nullptr)) return false;
    if (leftnode->data != rightnode->data) return false;
    
    bool leftside = helper(leftnode->left, rightnode->right);
    bool rightside = helper(leftnode->right, rightnode->left);

    return (leftside && rightside);

}

bool isSymmetric(node* root) {
    return helper(root->left, root->right);
}

int main() {
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(20);
    
    cout << isSymmetric(root);

}