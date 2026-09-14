#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    int data;

    node (int x) {
        left=right=nullptr;
        data=x;
    }
};

node* searchBST(node* root, int val) {
    if (root == nullptr) return nullptr;

    else if (val == root->data) return root;
    
    else if (val > root->data) {
        return searchBST(root->right, val);
    }
    
    else if (val < root->data) {
        return searchBST(root->left, val);
    }

}

int main() {
    node* root = new node(10);

    root->left = new node(5);
    root->right = new node(20);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->left->right->right = new node(8); 

    return 0;

}