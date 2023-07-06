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

int main() {
    string s="madam";
    int i=isPal(s,0);
    cout<<i;
    // int arr[]={1,2,3,4};
    // revArr(arr,4,0);
    // for (int i=0;i<4;i++) cout<<arr[i]<<' ';
    // printNum(1,4);
}