#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int x) {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

void helper(node* root, vector<int>& ans) {
    if (root==nullptr) return;

    helper(root->left, ans);

    ans.push_back(root->data);

    helper(root->right, ans);
}

vector<int> inorderTraversal(node* root) {
    vector<int> ans;

    helper(root, ans);

    return ans;
}

