#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int sr, int sc, vector<vector<int>> &vis, int color, int k) {
        int n = image.size();
        int m = image[0].size();
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                if (abs(delcol - delrow) == 1) {
                    int row = sr + delrow;
                    int col = sc + delcol;
                    if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && image[row][col] == k) {
                        dfs(image, row, col, vis, color, k);
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int k = image[sr][sc];
        dfs(image, sr, sc, vis, color, k);    
        return image;
    }