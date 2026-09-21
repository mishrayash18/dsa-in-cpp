#include <iostream>
#include <climits>
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

int helperone(node* root, int& maxd) {
    if (root==nullptr) return 0;
    if (root->left==nullptr && root->right==nullptr) return 1;
    
    int leftheight = helperone(root->left, maxd);
    int rightheight = helperone(root->right, maxd);

    int height = 1+max(leftheight, rightheight);

    maxd = max(maxd, leftheight+rightheight);

    return height;
}



int diameterOfBinaryTree(node* root) {
    int maxd = 0;
    int result = helperone(root, maxd);
    return maxd;

} 