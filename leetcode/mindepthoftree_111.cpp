#include <iostream>
#include <algorithm>
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

int minDepth(node* root) {
    if (root == nullptr)
        return 0;

    
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    
    if (root->left != nullptr && root->right == nullptr) {
        int leftheight = minDepth(root->left);
        return 1 + leftheight;
    }

    
    if (root->left == nullptr && root->right != nullptr) {
        int rightheight = minDepth(root->right);
        return 1 + rightheight;
    }

    
    int leftheight = minDepth(root->left);
    int rightheight = minDepth(root->right);

    return 1 + min(leftheight, rightheight);
}