#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
        for (int i=0;i<n;i++) {
            int num=1;
            for (int j=0;j<i+1;j++) {
                cout<<num++<<' ';
            }
            for (int k=0;k<(2*(n-i)-2);k++) {
                cout<<"  ";
            }
            num=i+1;
            for (int l=0;l<i+1;l++) {
                cout<<num--<<' ';
            }
            cout<<endl;
        }
    }

// 1                 1
// 1 2             2 1
// 1 2 3         3 2 1
// 1 2 3 4     4 3 2 1
// 1 2 3 4 5 5 4 3 2 1