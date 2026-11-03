#include <iostream>
#include <vector>
using namespace std;

struct node {
    node* left;
    int data;
    node* right;
};

void inorder(node* root, vector<int>& values) {
    if (root==nullptr) return;

    inorder(root->left, values);
    values.push_back(root->data);
    inorder(root->right, values);
}

bool IsUnivalTree(node* root) {
    vector<int> vals = {};
    inorder(root, vals);

    for (int i=0; i<vals.size()-1; i++) {
        if (vals[i]!=vals[i+1]) return false;
    }

    return true;
}