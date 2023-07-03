#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
        
        for (int i=0;i<n;i++) {
            int cnt=1;
            char ch='A';
            for (int j=0;j<n-i-1;j++) {
                cout<<' ';
                cnt++;
            }
            for (int k=0;k<2*i+1;k++) {
                if (cnt<n) {
                    cout<<ch;
                    ch=ch+1;
                    cnt++;
                }
                else {
                    cout<<ch;
                    ch=ch-1;
                    cnt++;
                }
            }
            cout<<endl;
                
        }
    }

//    A
//   ABA
//  ABCBA
// ABCDCBA