#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode()
    {
        this->data = 0;
        left = NULL;
    }
    TreeNode(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int data, TreeNode* left, TreeNode* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

bool isLeaf(TreeNode* root) {
    return (root -> left == NULL) && (root -> right == NULL);
}

void addLeftBoundary(TreeNode* root, vector<int> &left) {
    if (!root || isLeaf(root)) return;
    left.push_back(root -> data);
    if (root -> left) addLeftBoundary(root -> left, left);
    else addLeftBoundary(root -> right, left);
}

void addLeaves(TreeNode *root, vector<int> &leaf) {
    if (!root) return;
    addLeaves(root -> left, leaf);
    if (isLeaf(root) && root) leaf.push_back(root -> data);
    addLeaves(root -> right, leaf);   
}

void addRightBoundary(TreeNode* root, vector<int> &right) {
    if (!root || isLeaf(root)) return;
    if (root -> right) addRightBoundary(root -> right, right);
    else addRightBoundary(root -> left, right);
    right.push_back(root -> data);
}

vector<int> traverseBoundary(TreeNode* root){
    vector<int> ans, right;
    if (root == NULL) return ans;
    ans.push_back(root -> data);
    if (isLeaf(root)) return ans;
    addLeftBoundary(root -> left, ans);
    addLeaves(root, ans);
    addRightBoundary(root -> right, ans);
    return ans;
}