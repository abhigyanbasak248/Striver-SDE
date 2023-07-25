#include <bits/stdc++.h>
using namespace std;

//bfs
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < vertex; i++){
        sort(adj[i].begin(), adj[i].end()) ;
    }
    queue<int> q;
    vector<int> vis(vertex, 0);
    q.push(0);
    vis[0] = 1;
    vector<int> bfs;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        bfs.push_back(v);
        for (auto it : adj[v]) {
            if (vis[it] == 0) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
     for(int i = 0;i < vis.size(); i++){
        if(vis[i] == 0) bfs.push_back(i);
    }
    return bfs;
}

//dfs
void helper(vector<int> &dfs, vector<int> adj[], vector<int> &vis, int i) {
        dfs.push_back(i);
        vis[i] = 1;
        for (auto it : adj[i]) {
            if (!vis[it]) helper(dfs, adj, vis, it);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> dfs;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                helper(dfs, adj, vis, 0);
            }
        }
        return dfs;
        
    }