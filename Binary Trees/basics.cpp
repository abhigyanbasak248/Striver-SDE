#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

//create trees
Node* solve(vector<int>&arr, int i, int n) {
    Node* root = NULL;
    if (i < n) {
        root = new Node(arr[i]);
        root->left = solve(arr, 2 * i + 1, n);
        root->right = solve(arr, 2 * i + 2, n);
    }
    return root;
}
Node* createTree(vector<int>&arr){
    int n = arr.size();
    return solve(arr, 0, n);
}

//inorder traversal(iterative)
vector<int> inorderTraversal(Node* root) {
        vector<int> nodes;
        stack<Node*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> data);
            root = root -> right;
        }
        return nodes;
    }
//inorder(morris traversal)
vector<int> inorderTraversal(Node* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                Node* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(root -> data);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> data);
                root = root -> right;
            }
        }
        return nodes;
    }