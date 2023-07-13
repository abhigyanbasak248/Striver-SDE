#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

int firstOccurence(vector<int>& nums, int k) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == k) {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] > k) high = mid - 1;
        else low = mid + 1;
    }
    return first;
}

int lastOccurence(vector<int>& nums, int k) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == k) {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] > k) high = mid - 1;
        else low = mid + 1;
    }
    return last;
}

// to count ocuurrences: last-first+1