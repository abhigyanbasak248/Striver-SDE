#include <bits/stdc++.h>
using namespace std;

void printDiamond(int n) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n-i-1;j++)
                cout<<' ';
            for (int k=0;k<2*i+1;k++)
                if (k%2==0)
                    cout<<'*';
                else 
                    cout<<' ';
            cout<<endl;
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<i;j++)
                cout<<' ';
            for (int k=0;k<2*(n-i-1)+1;k++)
                if (k%2==0)
                    cout<<'*';
                else
                    cout<<' ';
            cout<<endl;
        }
    }

//     *
//    ***  
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *