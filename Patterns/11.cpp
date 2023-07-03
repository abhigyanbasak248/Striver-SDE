#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
        int start;
        for (int i=0;i<n;i++) {
            if (i%2==0)
                start=0;
            else 
                start=1;
            for (int j=0;j<2*i+1;j++) {
                if (j%2==0) {
                   if (start==1) {
                       start=0;
                       cout<<start;
                   }
                   else {
                       start=1;
                       cout<<start;
                   }
                }
                else
                    cout<<' ';
            }
            cout<<endl;
        }
    }

// 1 
// 0 1 
// 1 0 1
// 0 1 0 1 
// 1 0 1 0 1