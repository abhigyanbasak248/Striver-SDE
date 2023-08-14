#include <bits/stdc++.h>
using namespace std;

//method 1 O(2^n)
void printSubsequence(string input, string output, unordered_set<string> &s)
{
    if (input.empty()) {
        s.insert(output);
        return;
    }
    printSubsequence(input.substr(1), output + input[0], s);
    printSubsequence(input.substr(1), output, s);
}

//method 2, more optimal(need to sort string before)
void solve(string &a, int index, int &n, int &cnt){
    if(index==n){
        cnt++;
        return;
    }
    solve(a, index+1, n, cnt);
    while(index+1<n && a[index]==a[index+1]) index++;
    solve(a, index+1, n, cnt);
}