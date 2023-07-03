#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<2*i+1;j++) {
                if (j%2==0)
                    cout<<'*';
                else 
                    cout<<' ';
            }
            cout<<endl;
        }
        for (int i=1;i<n;i++) {
            for (int j=0;j<2*(n-i-1)+1;j++) {
                if (j%2==0)
                    cout<<'*';
                else 
                    cout<<' ';
            }
            cout<<endl;
        }
    }

// * 
// * * 
// * * * 
// * * * * 
// * * * * *
// * * * *
// * * *
// * *
// *