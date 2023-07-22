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

//height
int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }

//balanced BT(top-down)
int height(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = height(root->right);
        int rh = height(root->left);
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) > 1) return false;
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if (!l || !r) return false;
        return true;
    }

//bottom-up
int height(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = height(root->right);
        if (lh == -1) return -1;
        int rh = height(root->left);
        if (rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

//diameter(brute)
int height(TreeNode* root) {
    if (!root) return 0;
    
    return max(height(root->left) ,height(root->right)) +1;
}
void findMax(TreeNode* root, int &m) {
    if (!root) return;
    int lh = height(root -> left);
    int rh = height(root -> right);
    m = max(m, (lh + rh));
    findMax(root -> left, m);
    findMax(root -> right, m);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int m = 0;
    findMax(root, m);
    return m;
}

//diameter(optimal)
int height(TreeNode* root, int &m) {
    if (!root) return 0;
    int lh = height(root -> left, m);
    int rh = height(root -> right, m);
    m = max(m, (lh + rh));
    return max(lh, rh) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    int m = 0;
    height(root, m);
    return m;
}

//check if trees are same T: O(N), S: O(N)
bool check(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL || root2 == NULL) {
        return (root1 == root2);
    }
    return (root1->data == root2->data) && check(root1->left, root2->left) && check(root1->right, root2->right);
}
