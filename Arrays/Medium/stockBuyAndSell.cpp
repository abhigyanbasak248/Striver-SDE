#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        int n=prices.size();
        for (int i=0;i<n;i++) {
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(prices[i],mini);
        }
        return profit;
    }

int stockBuyAndSell(vector<int> &price) {
        int n=price.size();
        int sum=0;
        for (int i=1;i<n;i++) {
            if (price[i]>price[i-1]) {
                sum+=(price[i]-price[i-1]);
            }
        }
        return sum;
    }