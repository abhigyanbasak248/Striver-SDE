#include <bits/stdc++.h>
using namespace std;

//bfs
bool bfs(int sr, vector<int> adj[], vector<int> &vis) {
        queue<pair<int, int>> q;
        q.push({sr, -1});
        vis[sr] = 1;
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }


//dfs
bool dfs(int sr, int parent, vector<int> adj[], vector<int> &vis) {
        vis[sr] = 1;
        
        for (auto it : adj[sr]) {
            if (!vis[it]) {
                if (dfs(it, sr, adj, vis)) return true;
            }
            else if (it != parent) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }