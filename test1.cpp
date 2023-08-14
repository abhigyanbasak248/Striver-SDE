#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &v, int n, int sum, int left, int right, int &cnt) {
    if (right - left < 1) return;
    
    if (v[right] + v[right - 1] == sum) {
        ++cnt;
        helper(v, n, sum, left, right - 2, cnt);
        return;
    }
    else if (v[left] + v[left + 1] == sum) {
        ++cnt;
        helper(v, n, sum, left + 2, right, cnt);
        return;
    }
    else if (v[left] + v[right] == sum) {
        ++cnt;
        helper(v, n, sum, left + 1, right - 1, cnt);
        return;
    }
}

int solution(vector<int> &A) {
    int n = A.size();
    if (n < 2) {
        return 0;
    }
    int maxMoves = 0;
    int left = 0, right = n - 1;
    int sum1 = A[left] + A[right];
    int sum2 = A[left] + A[left + 1];
    int sum3 = A[right] + A[right - 1];
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    helper(A, n, sum1, left, right, cnt1);
    helper(A, n, sum2, left, right, cnt2);
    helper(A, n, sum3, left, right, cnt3);
    maxMoves = max(maxMoves, max(cnt1, max(cnt2, cnt3)));

    return cnt3;
}

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int main() {
    // vector<int> v1 = {4, 1, 4, 3, 3, 2, 5, 2};
    // vector<int> v2 = {1, 1, 2, 3, 1, 2, 2, 1, 1, 2};
    // cout<<solution(v2);
    int a , b;
   cout<<"Enter the values of a and b: "<<endl;
   cin>>a>>b;
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b);
   return 0;
}