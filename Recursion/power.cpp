#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
        // double ans = 1.0;
        // int nn = n;
        // if (nn < 0) nn = abs(nn);
        // while (nn) {
        //     if (nn % 2) {
        //         ans *= x;
        //         nn -=1;
        //     }
        //     else {
        //         x = x * x;
        //         nn /= 2;
        //     }
        // }
        // if (n < 0) ans = 1.0 / ans;
        // return ans;

        if (n == 0) return 1.0;
        else if (n % 2 == 0) {
            double y = myPow(x, n/2);
            return y * y;
        }
        else {
            return x * myPow(x, n - 1);
        }
    }