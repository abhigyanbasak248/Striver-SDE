#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n){
        int maxi=INT_MIN;
        vector<int> ans;
        // ans.push_back(arr[n-1]);
        for (int i=n-1;i>=0;i--) {
            if (arr[i]>=maxi) {
                ans.push_back(arr[i]);
            }
            maxi=max(maxi,arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }