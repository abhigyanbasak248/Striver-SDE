#include <bits/stdc++.h>
using namespace std;

void printSquare(int n) {
        for (int i=0;i<2*n-1;i++) {
            for (int j=0;j<2*n-1;j++) {
                cout<<(n-min(min(i,j),min(2*n-i-2,2*n-j-2)))<<' ';
            }
            cout<<endl;
        }
    }

// 4 4 4 4 4 4 4
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4