#include <bits/stdc++.h>
using namespace std;

int getCeil(int arr[], int n, int k) {
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= k) {
            ans = arr[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int getFloor(int arr[], int n, int k) {
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= k) {
            ans = arr[mid];
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int main() {
    double a=5;
    cout<<a+0.5;
}
