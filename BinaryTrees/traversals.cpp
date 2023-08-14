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

//level order traversal(queue)
 vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
                level.push_back(temp->data);
            }
            ans.push_back(level);
        }
        return ans;
    }

//zig-zag 1
vector<int> zigzagTreeTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> v(n, 0);
            for (int i = 0; i < n; i++)  {
                Node* curr = q.front();
                q.pop();
                int index = (leftToRight) ? i : (n - i -1);
                v[index] = curr -> data;

                if (curr -> left != NULL) q.push(curr -> left);
                if (curr -> right != NULL) q.push(curr -> right);
            }
            leftToRight = !leftToRight;
            for (auto it : v) ans.push_back(it);
        }
        return ans;
    }

//zig zag 2
vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    
    int l = 0;
    while (!q.empty()) {
        int size = q.size();
        int pos = ans.size();
        for (int i = 0; i < size; i++) {
            Node* top = q.front();
            q.pop();
            ans.push_back(top -> data);
            if (top -> left) {
                q.push(top -> left);
                // nodeCnt++;
            }
            if (top -> right) {
                q.push(top -> right);
                // nodeCnt++;
            }
        }
        if (l % 2 == 0 && pos >= 0) reverse(ans.begin() + pos, ans.end());
        l++;
    }
    return ans;
}

//preoder(iterative)
void preOrder(Node*root) {
    stack<Node*> s;
	s.push(root);
	while (!s.empty()) {
		Node* temp = s.top();
		s.pop();
		if (temp->right != NULL) s.push(temp->right);
		if (temp->left != NULL) s.push(temp->left);
		cout<<temp->data<<' ';
	}
}

//inorder(iterative)
vector<int> getInOrderTraversal(Node *root)
{
    stack<Node*> s;
    vector<int> ans;
    Node* node = root;
    while(true) {
        if (node != NULL) {
            s.push(node);
            node = node->left;
        }
        else {
            if (s.empty()) break;
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

//postorder(2 stacks)
vector<int> postorderTraversal(Node* root)
{
    stack<Node*> s1, s2;
    vector<int> ans;
    if (root == NULL) return ans; 
    s1.push(root);
    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp->left != NULL) s1.push(temp->left);
        if (temp->right != NULL) s1.push(temp->right);
    }
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}

//postorder(1 stack)
vector<int> postorderTraversal(Node* root)
{
    vector<int> ans;
    if (root == NULL) return ans;
    stack<Node*> s;
    Node* curr = root;
    while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = s.top()->right;
            if (temp == NULL) {
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while (!s.empty() && temp == s.top()->right) {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }
        }
    }
    return ans;
}

//all 3 traversals in 1 loop
vector<vector<int>> getTreeTraversal(Node *root){
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    vector<int> pre, inorder, post;
    stack<pair<Node*, int>> s;
    s.push({root, 1});
    while (!s.empty()) {
        auto it = s.top();
        s.pop();
        Node *curr = it.first;
        if (it.second == 1) {
            pre.push_back(curr->data);
            it.second++;
            s.push(it);
            if (curr->left != NULL) s.push({curr->left, 1});
        }
        else if (it.second == 2) {
            inorder.push_back(curr->data);
            it.second++;
            s.push(it);
            if (curr->right != NULL) s.push({curr->right, 1});
        }
        else {
            post.push_back(curr->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}