#include <bits/stdc++.h>
using namespace std;

vector<int> method1(vector<int> v1,vector<int> v2) {
    int i=0;
    int j=0;
    int n1=v1.size();
    int n2=v2.size();
    vector<int> intersectionArr;
    while (i<n1 && j<n2) {
        if (v1[i]==v2[j]) {
            intersectionArr.push_back(v1[i]);
            i++;
            j++;
            
        }
        else if (v1[i]<v2[j]){
            i++;
        }
        else {
            j++;
        }
    }
    return intersectionArr;
}

int main() {
    vector<int> v1{1,2,2,3,3,4,5,6};
    vector<int> v2{2,3,3,5,6,7};
    vector<int> v3=method1(v1,v2);
    for (auto i:v3) cout<<i<<' ';
}