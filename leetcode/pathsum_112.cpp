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

bool hasPathSum(node* root, int targetsum) {
    if (root == nullptr) return false;

    targetsum-=root->data;

    if (root->left== nullptr && root->right == nullptr && targetsum == 0) return true;

    else {
        bool leftans = hasPathSum(root->left, targetsum);
        bool rightans = hasPathSum(root->right, targetsum);
        return leftans || rightans;
    }

    
}

int main() {
    node* root1 = new node(10);

    root1->left = new node(5);
    root1->right = new node(20);

    root1->left->left = new node(3);
    root1->left->right = new node(7);

    root1->left->right->right = new node(8);

    

    cout << hasPathSum(root1, 18);

    return 0;

}