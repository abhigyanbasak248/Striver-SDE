#include <bits/stdc++.h>
using namespace std;

// reverse an array
void revArr(int arr[],int n,int i) {
    if (i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    revArr(arr,n,i+1);    
}

//palindrome
int isPal(string s,int i) {
    if (i>=s.length()/2) {
        return 1;
    }
    if (s[i]!=s[s.length()-i-1]) return 0;
    return isPal(s,i-1);
}

// print N-1
void printNum(int n) {
    if (n==0) return;
    cout<<n<<' ';
    printNum(n-1);
} 

//reverse a number
int sum = 0;
void rev(int num) {
    if (num == 0) return;
    int rem = num % 10;
    sum = sum * 10 + rem;
    rev(num / 10);
}

//returning a vector by creating it inside the function and not the argument
vector<int> findIndex(vector<int> arr, int target, int i) {
    vector<int> v;
    if (i == arr.size()) return v;

    if (arr[i] == target) v.push_back(i);
    vector<int> ans = findIndex(arr, target, i + 1);
    for (auto it : ans) v.push_back(it);
    return v;
}

int main() {
    // string s="madal";
    // int i=isPal(s,0);
    // cout<<i;
    // int arr[]={1,2,3,4};
    // revArr(arr,4,0);
    // for (int i=0;i<4;i++) cout<<arr[i]<<' ';
    // printNum(1,4);
    // int n = 1234;
    // rev(n);
    // cout<<sum;
    vector<int> v{1,2,3,3,4};
    vector<int> ans = findIndex(v, 3, 0);
    for(auto it : ans) cout<<it<<' ';
}