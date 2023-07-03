#include <bits/stdc++.h>
using namespace std;

//kadane's algorithm
int maxSubArray(vector<int>& nums) {
        int max=INT_MIN;
        int n=nums.size();
        int sum=0;
        int start=0;
        for (int i=0;i<n;i++) {
            sum+=nums[i];
            if (sum>max) {
                max=sum;
                ansStart=start;
                ansEnd=i;
            }
            if (sum<0) sum=0;
        }
        return max;
    }