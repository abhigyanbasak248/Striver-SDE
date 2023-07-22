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

int helper(TreeNode* root, int &m) {
        if (root == NULL) return 0;
        int lSum = max(0, helper(root -> left, m));
        int rSum = max(0, helper(root -> right, m));

        m = max (m, (lSum + rSum + root -> data));
        return max(lSum, rSum) + root -> data;
    }
    int maxPathSum(TreeNode* root) {
        int m = INT_MIN;
        helper(root, m);
        return m;
    }