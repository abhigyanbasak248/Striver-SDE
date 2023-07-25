#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& roads, vector<int>& vis, int i) {
        vis[i] = 1;
        for (int j = 0; j < roads[i].size(); ++j) {
            if (roads[i][j] == 1 && !vis[j]) {
                dfs(roads, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& roads) {
        int n = roads.size();
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cnt++;
                dfs(roads, vis, i);
            }
        }
        return cnt;
    }