#include <bits/stdc++.h>
using namespace std;

vector<int> method1(vector<int> v1,vector<int> v2) {
    set<int> s;
    int n1=v1.size();
    int n2=v2.size();
    for (int i=0;i<n1;i++) s.insert(v1[i]);
    for (int i=0;i<n2;i++) s.insert(v2[i]);
    vector<int> unionArr;
    for (auto &i:s) unionArr.push_back(i);
    return unionArr;
}

vector<int> method2(vector<int> v1,vector<int> v2) {
    int n1=v1.size();
    int n2=v2.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while (i<n1 && j<n2) {
        if (v1[i]<=v2[j]) {
            if (unionArr.size()==0 || unionArr.back()!=v1[i]) {
                unionArr.push_back(v1[i]);
            }
            i++;
        }
        else {
            if (unionArr.size()==0 || unionArr.back()!=v2[j]) {
                unionArr.push_back(v2[j]);
            }
            j++;
        }
    }
    while (i<n1) {
        if (unionArr.size()==0 || unionArr.back()!=v1[i]) {
            unionArr.push_back(v1[i]);
        }
        i++;
    }
    while (j<n2) {
        if (unionArr.size()==0 || unionArr.back()!=v2[j]) {
            unionArr.push_back(v2[j]);
        }
        j++;
    }
    return unionArr;
}

vector<int> method3(vector<int> v1,vector<int> v2) {
    int n1=v1.size();
    int n2=v2.size();
    map<int,int> freq;
    vector<int> unionArr;
    for (auto i :v1) {
        freq[i]++;
    }
    for (auto i:v2) {
        freq[i]++;
    }
    for (auto it:freq) unionArr.push_back(it.first);
    return unionArr;
}

int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{1,2,3,4,5};
    vector<int> v3=method3(v1,v2);
    for (auto i:v3) cout<<i<<' ';
}