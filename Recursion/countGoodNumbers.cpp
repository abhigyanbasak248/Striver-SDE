#include <bits/stdc++.h>
using namespace std;
#define ll long long

//codestudio
bool check(int num, int &sum, int digit) {
	if (num == 0) return true;
	int rem = num % 10;
	if (rem == digit || rem <= sum) return false;
	num /= 10;
	if (sum == -1) sum = 0;
	sum += rem;
	return check(num, sum, digit);
}

vector<int> goodNumbers(int a, int b, int digit) {
	vector<int> ans;
	for (int i = a; i <= b; ++i) {
		int sum = -1;
		if (check(i, sum, digit)) ans.push_back(i);
	}
	return ans;
}

//leetcode
const int mod = 1e9 + 7;
    long long power(long long n, long long x) {
        if (x == 0) return 1;
        if (x % 2) {
            return n * power(n, x - 1) % mod;
        }
        else {
            return power((n * n) % mod, x / 2) % mod;
        }
    }
    int countGoodNumbers(long long n) {
        ll ans = ((power(5, (n + 1) / 2) * power(4, n / 2) % mod) % mod);
        return (int)ans;
    }