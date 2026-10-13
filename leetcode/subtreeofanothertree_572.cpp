#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int x) {
        data=x;
        left=right=nullptr;
    }
};

bool helper(node* root1, node* root2) {
    if (root1==nullptr && root2==nullptr) return true;
    if (root1==nullptr || root2==nullptr) return false;
    if (root1->data != root2->data) return false;

    bool leftSame = helper(root1->left, root2->left);
    bool rightSame = helper(root1->right, root2->right);

    return leftSame && rightSame;
}


bool isSubtree(node* root, node* subroot) {
    if (root==nullptr && subroot==nullptr) return true;
    if ((root==nullptr && subroot!=nullptr) || (root!=nullptr && subroot==nullptr)) return false;

    if (root->data == subroot->data) {
        bool subtreeatcurrnode = helper(root, subroot);
        if (subtreeatcurrnode == true) return true;
    }

    bool leftvalue = isSubtree(root->left, subroot);
    bool rightvalue = isSubtree(root->right, subroot);

    return (leftvalue || rightvalue);
}