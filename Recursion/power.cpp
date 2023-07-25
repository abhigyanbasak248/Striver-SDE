#include <bits/stdc++.h>
using namespace std;

//iterative
double myPow(double x, long long n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = abs(nn);
        while (nn) {
            if (nn % 2) {
                ans *= x;
                nn -=1;
            }
            else {
                x = x * x;
                nn /= 2;
            }
        }
        if (n < 0) ans = 1.0 / ans;
        return ans;
    }

//recursive
double myPow(double x, long long n) {
    if (n == 0) return 1.0;
        if (n < 0) return 1 / myPow(x, abs(n));
        if (n % 2) {
            return x * myPow(x, n - 1);
        }
        else {
            return myPow(x * x, n/2);
        }
}