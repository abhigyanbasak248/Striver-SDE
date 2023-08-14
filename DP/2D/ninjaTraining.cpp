#include <bits/stdc++.h>
using namespace std;

int f(int i, int t, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (i == 0) {
        int maxi = 0;
        for (int j = 0; j < 3; j++) {
            if (j != t) {
                maxi = max(maxi, points[i][j]);
            }
        }
        return maxi;
    }
    if (dp[i][t] != -1) return dp[i][t];
    int maxi = 0;
    for (int j = 0; j < 3; j++) {
        if (j != t) {
            int maxPoints = points[i][j] + f(i - 1, j, points, dp);
            maxi = max(maxi, maxPoints);
        }
    }
    return dp[i][t] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, 0);
    // return f(n - 1, 3, points, dp);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int i = 1; i < n; i++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
            for (int t = 0; t < 3; t++) {
                if (t != last) {
                    int maxPoints = points[i][t] + dp[t];
                    temp[last] = max(temp[last], maxPoints);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}