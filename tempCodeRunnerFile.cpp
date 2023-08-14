void helper(vector<int> &v, int n, int sum, int left, int right, int &cnt) {
    if (right - left < 2) return;
    
    if (v[left] + v[left + 1] == sum) {
        ++cnt;
        helper(v, n, sum, left + 2, right, cnt);
    }
    if (v[left] + v[right] == sum) {
        ++cnt;
        helper(v, n, sum, left + 1, right - 1, cnt);
    }
    if (v[right] + v[right - 1] == sum) {
        ++cnt;
        helper(v, n, sum, left, right - 2, cnt);
    }
}

int solution(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
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
    
    // for (int i = 0; i < N; i++) {
    //     int sum = A[i];
    //     int left = 0, right = N - 1;
    //     int moves = 0;
    //     while (left < right) {
    //         if (A[left] + A[right] == sum) {
    //             ++moves;
    //             left += 2;
    //             right -= 2;
    //         }
    //         else if (A[left] + A[right] < sum) {
    //             ++left;
    //         }
    //         else {
    //             --right;
    //         }
    //     }
    //     maxMoves = max(maxMoves, moves);
    // }
    return cnt1;
}