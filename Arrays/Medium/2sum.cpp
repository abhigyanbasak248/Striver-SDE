#include <bits/stdc++.h>
using namespace std;

//brute
vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            for (int j=i+1;j<nums.size();j++) {
                if (nums[i]+nums[j]==target) {
                    res.push_back(i);
                    res.push_back(j);   
                }
            }
        }
        return res;
    }

//better (use unordered map)
vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> index;
        map<int,int> arrayElements;
        int sum=0;
        int n=nums.size();
        for (int i=0;i<n;i++) {
            int rem=target-nums[i];
            if (arrayElements.find(rem)!=arrayElements.end()) {
                index.push_back(min(i,arrayElements[rem]));
                index.push_back(max(i,arrayElements[rem]));
            }
            arrayElements[nums[i]]=i;
        }
        return index;
    }

//optimal(not for returning index)
vector<int> twoSum3(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> index;
        int n=nums.size();
        int left=0,right=n-1;
        while (left<right) {
            int sum=nums[left]+nums[right];
            if (sum==target) {
                index.push_back(left);
                index.push_back(right);
                break;
            }
            else if (sum>target) right--;
            else left++;
        }
        return index;
    }


