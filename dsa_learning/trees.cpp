// CREATING A BASIC TREE DS
// #include <iostream>
// using namespace std;

// struct node {
//     int data;
//     node* left;
//     node* right;

//     node(int x) {
//         data=x;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// int main() {
//     node* root = new node(10);
//     root->left = new node(20);
//     root->right = new node(30);

//     return 0;
// }



// FINDING THE HEIGHT  OF A TREE USING BACKTRACKING
// #include <iostream>
// using namespace std;

// struct node {
//     int data;
//     node* left;
//     node* right;

//     node(int x) {
//         data=x;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// int height(node* root) {
//     if (root == nullptr) return 0;

//     int leftheight = height(root->left);
//     int rightheight = height(root->right);

//     int myheight = 1+max(leftheight,rightheight);

//     return myheight;
// }


// int main() {
//     node* root = new node(10);

//     root->left = new node(5);
//     root->right = new node(20);

//     root->left->left = new node(3);
//     root->left->right = new node(7);

//     root->left->right->right = new node(8);

//     cout<<height(root);
//     return 0;

// }




// DFS TRAVERSAL
// PREORDER TRAVERSAL
// #include <iostream>
// using namespace std;


// struct node {
//     int data;
//     node* left;
//     node* right;

//     node(int x) {
//         data=x;
//         left=nullptr;
//         right=nullptr;
//     }
// };


// void preorder(node* root) {
//     if (root == nullptr) return;

//     cout << root->data << endl;
//     preorder(root->left);
//     preorder(root->right);
// }

// void inorder(node* root) {
//     if (root == nullptr) return;

//     inorder(root->left);
//     cout << root->data << endl;
//     inorder(root->right);
// }

// void postorder(node* root) {
//     if (root == nullptr) return;

//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << endl;
// }

// int main() {
//     node* root = new node(10);

//     root->left = new node(5);
//     root->right = new node(20);

//     root->left->left = new node(3);
//     root->left->right = new node(7);

//     root->left->right->right = new node(8);

//     preorder(root);
//     inorder(root);
//     postorder(root);

// }