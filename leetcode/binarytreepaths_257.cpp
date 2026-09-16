#include <iostream>
#include <vector>
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

void helper(node* root, vector<int>& currentpath, vector<vector<int>>& allpaths) {
    if (root==nullptr) return;
    
    currentpath.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr) allpaths.push_back(currentpath);

    helper(root->left, currentpath, allpaths);
    helper(root->right, currentpath, allpaths);

    currentpath.pop_back();
    
}

vector<string> binaryTreePaths(node* root) {
    vector<int> currentpath;
    vector<vector<int>> allpaths;
    vector<string> result;

    helper(root, currentpath, allpaths);

    for (vector<int> path : allpaths) {
        string s = "";
        for (int i=0; i<path.size(); i++) {
            s+=to_string(path[i]);
            s+="->";
        }
        s.pop_back();
        s.pop_back();
        result.push_back(s);
    }

    return result;
}

int main() {
    node* root = new node(10);

    root->left = new node(5);
    root->right = new node(20);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->left->right->right = new node(8);

    vector<string> ans = binaryTreePaths(root);

    for (string s : ans) {
        cout << s << endl;
    }
    return 0;

}