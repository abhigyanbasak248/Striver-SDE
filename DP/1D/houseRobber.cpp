#include <bits/stdc++.h>
using namespace std;

//house robber 1
int solve(int i, vector<int> &nums, vector<int> &dp) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    int take = nums[i] + solve(i - 2, nums, dp);
    int notake = solve(i - 1, nums, dp);
    return dp[i] = max(take, notake);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // vector<int> dp(n, 0);
    // return solve(n - 1, nums, dp);
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += prev2;
        int notake = prev;
        int curr = max(take, notake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

//house robber 2
int sol(vector<int> &nums, int start, int end) {
        int prev2 = 0, prev = nums[start];
        for (int i = start + 1; i < end; i++) {
            int take = nums[i];
            if (i > 1) take += prev2;
            int notake = prev;
            int curr = max(take, notake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int first = sol(nums, 0, n - 1);
        int last = sol(nums, 1, n);
        return max(first, last);
    }