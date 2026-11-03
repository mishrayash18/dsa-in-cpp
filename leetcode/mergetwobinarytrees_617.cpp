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

int helper(node* root1, node* root2) {

}

node* mergetrees(node* root1, node* root2) {
    if (root1==nullptr && root2==nullptr) return nullptr;
    if (root1==nullptr && root2!=nullptr) return root2;
    if (root2==nullptr && root1!=nullptr) return root1;

    node* mergedleft = mergetrees(root1->left, root2->left);
    node* mergedright = mergetrees(root1->right, root2->right);

    node* mergednode = new node(root1->data + root2->data);

    mergednode->left = mergedleft;
    mergednode->right = mergedright;

    return mergednode;

}