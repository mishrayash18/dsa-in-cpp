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

int sumOfLeftLeaves(node* root) {
    if (root == nullptr) return 0;

    int sum = 0;

    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) sum+=root->left->data;

    int leftsum = sumOfLeftLeaves(root->left);
    int rightsum = sumOfLeftLeaves(root->right);

    return (sum+=leftsum+rightsum);
}

int main() {
    node* root = new node(10);

    root->left = new node(5);
    root->right = new node(20);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->left->right->right = new node(8);

    cout<<sumOfLeftLeaves(root);
    return 0;

}