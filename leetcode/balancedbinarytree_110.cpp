#include <iostream>
using namespace std;

struct node {
    node* left;
    int data;
    node* right;

    node (int x) {
        data=x;
        left=right=nullptr;
    }
};

int helper(node* root) {
    if (root==nullptr) return 0;
    if (root->left==nullptr && root->right==nullptr) return 1;

    int leftheight = helper(root->left);
    int rightheight = helper(root->right);

    int height = 1+max(leftheight, rightheight);

    return height;
}

bool isBalanced(node* root) {
    if (root == nullptr) return true;

    bool leftbalanced = isBalanced(root->left);
    bool rightbalanced = isBalanced(root->right);

    int leftheight = helper(root->left);
    int rightheight = helper(root->right);

    if ((abs(leftheight-rightheight)<=1) && (leftbalanced&&rightbalanced)) return true;
    else return false;
    
}