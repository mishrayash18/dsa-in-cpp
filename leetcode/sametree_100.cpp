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


bool sameTree(node* root1, node* root2) {
    if (root1 == nullptr && root2 == nullptr) return true;

    if (root1 == nullptr || root2 == nullptr) return false;

    if (root1->data != root2->data) return false;

    bool leftsame = sameTree(root1->left, root2->left);
    bool rightsame = (root1->left, root2->right);

    return leftsame && rightsame;
}


int main() {
    node* root1 = new node(10);

    root1->left = new node(5);
    root1->right = new node(20);

    root1->left->left = new node(3);
    root1->left->right = new node(7);

    root1->left->right->right = new node(8);

    
    node* root2 = new node(10);

    root2->left = new node(5);
    root2->right = new node(20);

    root2->left->left = new node(3);
    root2->left->right = new node(7);

    root2->left->right->right = new node(8);

    cout << sameTree(root1, root2);

    return 0;

}