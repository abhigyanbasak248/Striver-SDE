#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int n = nums.size();
        int preSum = 0;
        int cnt = 0;
        for (int i = 0;i<n;i++) {
            preSum += nums[i];
            int rem = preSum - k;
            cnt += mpp[rem];
            mpp[preSum]++;
        }
        return cnt;
    }