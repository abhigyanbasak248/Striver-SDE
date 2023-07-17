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

//searching 1
TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root -> data == val) return root;
        else if (val > root -> data) return searchBST(root -> right, val);
        else return searchBST(root -> left, val);
    }

//searching 2
bool search(TreeNode* root, int x) {
    while (root != NULL) {
        if (root -> data == x) return true;
        else if (x > root -> data) root = root -> right;
        else root = root -> left;
    }
    return false;
}

