#include <bits/stdc++.h>
using namespace std;

//approach 1
void recurPermute(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,vector<bool> &freq) {
        if (ds.size()==nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            if (!freq[i]) {
                freq[i]=true;
                ds.push_back(nums[i]);
                recurPermute(nums,ans,ds,freq);
                ds.pop_back();
                freq[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<bool> freq(n, false);
        vector<int> ds;
        recurPermute(nums,ans,ds,freq);
        return ans;
    }

//approach 2
void recurPermute(vector<int>& nums,vector<vector<int>>& ans,int index) {
        if (index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i=index;i<nums.size();i++) {
            swap(nums[index],nums[i]);
            recurPermute(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(nums,ans,0);
        return ans;
    }