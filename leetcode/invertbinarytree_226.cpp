#include <iostream>
using namespace std;

struct node {
    node* left;
    int data;
    node* right;

    node(int x) {
        left=right=nullptr;
        data=x;
    }
};

node* invertTree(node* root) {

    if (root == NULL) return root;

    node* leftnode = invertTree(root->left);
    node* rightnode = invertTree(root->right);

    root->right = leftnode;
    root->left = rightnode;

    return root;
}

int main() {
    node* root = new node(10);

    root->left = new node(5);
    root->right = new node(20);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->left->right->right = new node(8);

    node* newroot = invertTree(root);


    return 0;

}