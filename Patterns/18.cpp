#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
        
        for (int i=0;i<n;i++) {
            char ch='A'+n-1;
            for (int j=0;j<=i;j++) {
                cout<<ch--<<" ";
            }
            cout<<endl;
        }
    }

// E
// E D
// E D C
// E D C B
// E D C B A