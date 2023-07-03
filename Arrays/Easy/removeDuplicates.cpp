#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[],int n) {
    int i=0;
    for (int j=1;j<n;j++) {
        if (arr[i]!=arr[j]) {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main() {
    int arr[]={3,4,4,5,6,6,6,7};
    int n=removeDuplicates(arr,8);
    for (int i=0;i<n;i++) cout<<arr[i]<<' ';
}