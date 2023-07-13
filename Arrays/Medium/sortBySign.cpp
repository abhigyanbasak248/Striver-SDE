#include <bits/stdc++.h>
using namespace std;

//for unequal no. of pos and neg
void rearrange(int arr[], int n) {
	    vector<int> pos,neg;
	    for (int i=0;i<n;i++) {
	        if (arr[i]<0) neg.push_back(arr[i]);
	        else pos.push_back(arr[i]);
	    }
	    
	    if (pos.size()==neg.size()) {
	        for (int i=0;i<n/2;i++) {
	            arr[2*i]=pos[i];
	            arr[2*i+1]=neg[i];
	        }
	    }
	    else if (pos.size()>neg.size()) {
	        for (int i=0;i<neg.size();i++) {
	            arr[2*i]=pos[i];
	            arr[2*i+1]=neg[i];
	        }
	        for (int i=neg.size(),j=2*neg.size();i<pos.size(),j<n;i++,j++) {
	            arr[j]=pos[i];
	        }
 	    }
 	    else {
 	        for (int i=0;i<pos.size();i++) {
	            arr[2*i]=pos[i];
	            arr[2*i+1]=neg[i];
	        }
	        for (int i=pos.size(),j=2*pos.size();i<neg.size(),j<n;i++,j++) {
	            arr[j]=neg[i];
	        }
 	    }
}

//for equal no. of pos and neg
vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int posIndex=0,negIndex=1;
        for (int i=0;i<n;i++) {
            if (nums[i]>0) {
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
            else {
                ans[negIndex]=nums[i];
                negIndex+=2;
            }
        }
        return ans;
}