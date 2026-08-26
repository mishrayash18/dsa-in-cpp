#include <iostream>
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

int maxdepth(node* root) {
    if (root==nullptr) return 0;

    int leftheight = maxdepth(root->left);
    int rightheight = maxdepth(root->right);

    int myheight = 1+max(leftheight, rightheight);

    return myheight;
}

int main() {
    node* root = new node(10);

    root->left = new node(5);
    root->right = new node(20);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->left->right->right = new node(8);

    cout<<maxdepth(root);
    return 0;

}