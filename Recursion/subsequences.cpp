#include <bits/stdc++.h>
using namespace std;

//recursive
void subsequences(vector<vector<int>> &ans, vector<int> seq, vector<int> &nums, int i) {
        if (i >= nums.size()) {
            ans.push_back(seq);
            seq.clear();
            return;
        }
        seq.push_back(nums[i]);
        subsequences(ans, seq, nums, i + 1);
        seq.pop_back();
        subsequences(ans, seq, nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        subsequences(ans, v, nums, 0);
        return ans;
    }

//bit manipulation
vector<string> generateSubsequences(string str)
{
    vector<string> ans;
	int n = str.length();
	for (int i = 1; i < pow(2, n); i++) {
		string sub = "";
		for (int j = 0; j < n; j++){
			if (i & (1<<j)) sub += str[j];
		}
		ans.push_back(sub);
	}
	return ans;
}