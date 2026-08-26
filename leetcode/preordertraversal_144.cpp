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

void helper(node* root, vector<int> ans) {
    if (root == nullptr) return;

    ans.push_back(root->data);
    helper(root->left, ans);
    helper(root->right, ans);
}

vector<int> preorderTraversal(node* root) {
    vector<int> ans;

    helper(root, ans);

    return ans;
}

int main() {
    node* root = new node(10);

    root->left = new node(5);
    root->right = new node(20);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->left->right->right = new node(8);

    vector<int> result = preorderTraversal(root);

    for (int val:result) {
        cout << val << endl;
    }

    return 0;

}