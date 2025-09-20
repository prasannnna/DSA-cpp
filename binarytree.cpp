#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
    public:
    Node* root;
    BinaryTree() {
        root = nullptr;
    }
    Node* buildTree(vector<int>arr, int i) {
        if(i >= arr.size() || arr[i] == -1) return nullptr;
        Node* node = new Node(arr[i]);
        node->left = buildTree(arr, (2 * i) + 1);
        node->right = buildTree(arr, (2 * i) + 2);
        return node;
    }
    void printinorder(Node* root) {
        if(!root) return;
        printinorder(root->left);
        cout << root->data << " ";
        printinorder(root->right);
    }
    void levelorder(Node* root) {
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                cout << q.front()->data << " ";
                Node* value = q.front();
                q.pop();
                if(value->left) q.push(value->left);
                if(value->right) q.push(value->right);
            }
            cout << "\n";
        }
    }
    int treeHeight(Node* root) {
        if(!root) return -1;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }
};

int main() {
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    BinaryTree tree;
    tree.root = tree.buildTree(arr, 0);
    if(tree.root == nullptr){ 
        cout << "Tree is Empty\n";
    }
    else {
        tree.printinorder(tree.root);
        cout << "\n";
        tree.levelorder(tree.root);
        cout << "Tree Height: " << tree.treeHeight(tree.root);
    }
}
