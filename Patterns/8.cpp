#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
	    for (int i=0;i<n;i++) {
	        for (int j=0;j<i;j++)
	            cout<<' ';
	        for (int k=0;k<(2*(n-i-1)+1);k++)
	            cout<<'*';
	        cout<<endl;
	    }
	}

// *********
//  *******
//   *****
//    ***
//     *