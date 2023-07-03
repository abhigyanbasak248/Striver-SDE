#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
        int spaces=2*n-2;
        for (int i=0;i<2*n-1;i++) {
            for (int j=0;j<(n-spaces/2);j++) cout<<'*';
            for (int j=0;j<spaces;j++) cout<<" ";
            for (int j=0;j<(n-spaces/2);j++) cout<<'*';
            if (i<n-1) spaces-=2;
            else spaces+=2;
            cout<<endl;
        }
    }

// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *