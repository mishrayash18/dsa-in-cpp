// creating a basic tree ds
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

int main() {
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(30);

    return 0;
}