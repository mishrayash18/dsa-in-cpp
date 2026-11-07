#include <iostream>
#include <math.h>
using namespace std;

struct node {
    node* left;
    int data;
    node* right;

    node(int x) {
        data=x;
        left=right=nullptr;
    }
};

int leftheight(node* root) {
    if (root==nullptr) return 0;
    int height = 0;
    node* temp = root;
    while (temp!=nullptr) {
        height++;
        temp = temp->left;
    }
    return height;
}

int rightheight(node* root) {
    if (root==nullptr) return 0;
    int height = 0;
    node* temp = root;
    while (temp!=nullptr) {
        height++;
        temp = temp->right;
    }
    return height;
}


int countnodes(node* root) {
    if (root==nullptr) return 0;

    int left = leftheight(root);
    int right = rightheight(root);

    if (left==right) {
        return pow(2, left)-1;
    }

    int leftnodes = countnodes(root->left);
    int rightnodes = countnodes(root->right);

    int count = 1+leftnodes+rightnodes;
    return count;

}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    int count = countnodes(root);
    cout << count;
    return 0;
}