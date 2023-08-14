#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &heights, int i, vector<int> &dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int left = solve(heights, i - 1, dp) + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;
    if (i > 1)
        right = solve(heights, i - 2, dp) + abs(heights[i] - heights[i - 2]);
    return dp[i] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    // vector<int> dp(n, 0);
    // return solve(heights, n - 1, dp);
    // dp[0] = 0;
    int prev = 0, prev2 = 0;
    for (int i = 1; i < n; i++) {
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1) ss = prev2 + abs(heights[i] - heights[i - 2]);

        int curi = min(fs, ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}


//jump with k steps
int f(int i, int k, vector<int> &height, vector<int> &dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int minstep = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int jump = f(i - j, k, height, dp) + abs(height[i] - height[i - j]);;
            minstep = min(minstep, jump);
        }
        dp[i] = minstep;
    }
    return dp[i];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, -1);
    return f(n - 1, k, height, dp);
    // for (int i = 1; i < n; i++) {
    //   int minsteps = INT_MAX;
    //   for (int j = 1; j <= k; j++) {
    //     if (i - j >= 0) {
    //       int jump = dp[i - j] + abs(height[i] - height[i - j]);
    //       minsteps = min(minsteps, jump);
    //     }
    //   }
    //   dp[i] = minsteps;
    // }
    // return dp[n - 1];
}