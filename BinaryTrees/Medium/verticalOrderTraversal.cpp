#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//iterative
vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int v = it.second.first;
            int l = it.second.second;
            TreeNode* temp = it.first;
            nodes[v][l].insert(temp -> val);
            if (temp -> left) q.push({temp -> left, {v - 1, l + 1}});
            if (temp -> right) q.push({temp -> right, {v + 1, l + 1}}); 
        }
        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

//recursive
void traversal(map<int, map<int, multiset<int>>> &nodes, TreeNode *root, int v, int l) {
        if (!root) return;
        nodes[v][l].insert(root -> val);
        traversal(nodes, root -> left, v - 1, l + 1);
        traversal(nodes, root -> right, v + 1, l + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        map<int, map<int, multiset<int>>> nodes;
        int l = 0, v = 0;
        traversal(nodes, root, v, l);
        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

//top view
vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int, int> nodes;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* curr = it.first;
            int v = it.second;
            if (nodes.find(v) == nodes.end()) nodes[v] = curr -> val;
            if (curr -> left) q.push({curr -> left, v - 1});
            if (curr -> right) q.push({curr -> right, v + 1});
        }
        for (auto it : nodes) {
            ans.push_back(it.second);
        }
        return ans;
    }

//bottom view
vector<int> bottomView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int, int> nodes;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* curr = it.first;
            int v = it.second;
            nodes[v] = curr -> val;
            if (curr -> left) q.push({curr -> left, v - 1});
            if (curr -> right) q.push({curr -> right, v + 1});
        }
        for (auto it : nodes) {
            ans.push_back(it.second);
        }
        return ans;
    }

//right or left view
void traversal(TreeNode* root, map<int, int> &nodes, int l) {
        if (root == NULL) return;
        nodes[l] = root -> val;
        if (root -> left) traversal(root -> left, nodes, l + 1);
        if (root -> right) traversal(root -> right, nodes, l + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        map<int, int> nodes;
        traversal(root, nodes, 0);
        for (auto it : nodes) {
            ans.push_back(it.second);
        }
        return ans;
    }