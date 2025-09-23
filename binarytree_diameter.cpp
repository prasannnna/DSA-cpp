#include<bits/stdc++.h>
using namespace std;

class Tree {
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) {
        data = val;
        left = right = nullptr;
    }
    
};

class BinaryTree {
    public:
     Tree* root;
     BinaryTree() {
        root = nullptr;
     }
     Tree* buildTree(vector<int>&arr, int i) {
        if(arr[i] == -1 || i >= arr.size()) {
            return nullptr;
        }
        Tree* child = new Tree(arr[i]);
        child->left = buildTree(arr, (2*i) + 1);
        child->right = buildTree(arr, (2*i) + 2);   
        return child; 
    }
    int tree_height(Tree* root) {
        if(!root) return 0;
        return 1 + max(tree_height(root->left), tree_height(root->right));
    }
    int tree_diameter(Tree* root) {
        if(!root) return 0;
        int lheight = tree_height(root->left);
        int rheight = tree_height(root->right);
        int heights = lheight + rheight;
        int ld = tree_diameter(root->left);
        int rd = tree_diameter(root->right);
        return max(heights, max(ld, rd));
    }
};

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    BinaryTree tree;
    tree.root = tree.buildTree(arr, 0);
    int diameter = tree.tree_diameter(tree.root);
    cout << diameter;
}