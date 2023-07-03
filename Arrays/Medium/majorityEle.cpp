#include <bits/stdc++.h>
using namespace std;

//Moore's voting algorithm
int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=1;
        int n=nums.size();
        for (int i=1;i<n;i++) {
            if (cnt==0) {
                ele=nums[i];
                cnt=1;
                continue;
            }
            if (nums[i]==ele) cnt++;
            else cnt--;
        }
        int actualCnt=0;
        for (int i=0;i<n;i++) {
            if (nums[i]==ele) actualCnt++;
        }
        if (actualCnt<=n/2) ele=-1;
        return ele;
    }